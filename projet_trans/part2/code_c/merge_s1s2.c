/*
    acquisition de donnees sur le port serie (entre 0 et 255) par frames de 1024 elements
    calcul de la fft de la frame
    affichage graphique du resultat sur le terminal (ouvrir la fenetre en plein ecran)

    @authors: Cocogne, Combal, Chbada, El Hachimi
*/
#include "header.h"


/*
    initialise la liaison serie
*/
void initTermios(struct termios *termios_t, int fd){

    tcgetattr(fd,termios_t);                             // Lecture des parametres courants

    termios_t->c_cflag = B115200 | CS8 | CREAD | CLOCAL;   // Liaison a 115200 bps avec 8 bits de donnees deux bits de stop  et une parite paire 
    termios_t->c_iflag = IGNBRK | IGNPAR;                  // Ignore les BREAK et les caracteres avec erreurs de parite 
    termios_t->c_oflag = 0;                                // Pas de mode de sortie particulier 
    termios_t->c_lflag = ECHO;                             // Mode non-canonique 

    termios_t->c_cc[VMIN] = 1;                             // Caracteres immediatement disponibles avec VMIN la taille du BUFFER de la liaison en serie  
    termios_t->c_cc[VTIME] = 0;

    termios_t->c_ispeed= B115200;
    cfsetispeed(termios_t,B115200);
    tcflush(fd,TCIFLUSH);

    tcsetattr(fd,TCSANOW,termios_t);                     // Sauvegarde des nouveaux parametres 

}

int main(){

    char c;
    int fd, res;
    struct termios termios_t;
    double data[BUFFER_LEN];
    double dataout[SIZE];

//ouverture de la liaison serie
	if ( (fd=open("/dev/ttyS1",O_RDWR|O_NONBLOCK)) == -1 ) {
		perror("open");
		exit(-1);
	}
//initialisation du terminal en mode communication serie
    initTermios(&termios_t,fd);

	while(1) {

		for(int i=0;i<BUFFER_LEN;i++){
			while((res=read(fd,&c,1))==-1); //on attend la reception d'un caractere
			data[i]=(double)c;			    //on le lit
        }
        process_data(dataout,data,BUFFER_LEN,1,2); //traitement des donnees
        printf("\e[2J");                           //rafraichissement de l'ecran
        plot(dataout,SIZE);                        //affichage
    }
    return EXIT_SUCCESS;
}
		

		


		
				



