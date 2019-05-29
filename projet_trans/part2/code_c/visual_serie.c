/*
    acquisition de donnees sur le port serie (entre 0 et 255) par frames de 1024 elements
    calcul de la fft de la frame
    affichage graphique du resultat sur le terminal (ouvrir la fenetre en plein ecran)
    pour faire le make, commenter l'autre main et decommenter celui-ci, puis 
    changer le nom de l'executable dans le makefile

    @authors: Cocogne, Combal, Chbada, El Hachimi
*/
#include "header.h"


/*
    initialise la liaison serie
*/
void initTermios(struct termios *termios_t, int fd){

    tcgetattr(fd,termios_t);                             // Lecture des parametres courants

    /*
    *B115200:  Vitesse bps
    *CS8: Masque de longueur des caractères
    *CREAD:Valider la réception
    *CLOCAL:Ignorer les signaux de contrôle du modem
    */
    termios_t->c_cflag = B115200 | CS8 | CREAD | CLOCAL;   

    /*
    *IGNBRK:Ignorer les signaux BREAK en entrée
    *IGNPAR:Ignorer les erreurs de format et de parité 
    */
    termios_t->c_iflag = IGNBRK | IGNPAR;                 
    termios_t->c_oflag = 0;    

    /*
    *ECHO:Effectuer un écho des caractères saisis
    */                            
    termios_t->c_lflag = ECHO;                             

    /*
    * Nombre minimum de caractères lors d'une lecture en mode non canonique  
    */  
    termios_t->c_cc[VMIN] = 1;                            
    termios_t->c_cc[VTIME] = 0;
    /*
    *fixe la vitesse d'entrée stockée dans la structure termios à la valeur speed
    *speed = B115200
    */
    termios_t->c_ispeed= B115200;
    cfsetispeed(termios_t,B115200);

    /*
    *élimine toutes les écritures sur l'objet fd pas encore transmises, 
    *ainsi que les données reçues mais pas encore lues
    */
    tcflush(fd,TCIFLUSH);

    /*
    *fixe les paramètres du terminal (à moins que le matériel sous-jacent ne le prenne pas en charge) 
    *en lisant la structure termios pointée par termios_t
    */
    tcsetattr(fd,TCSANOW,termios_t);                     

}

int main(){

    char c;
    int fd, res;
    struct termios termios_t;
    double data[BUFFER_LEN];
    double dataout[SIZE];

/*
* Ouverture de la liaison serie
* O_RDWR: mode d'accès R/W
* O_NONBLOCK:Le fichier est ouvert en mode « non bloquant ». Ni la fonction open() ni aucune autre opération ultérieure sur ce fichier ne laissera le processus appelant en attente
* ttyS1: périphériques série correspondants à COM2
*/
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
        plot(dataout,SIZE,120);                    //affichage
    }
    return EXIT_SUCCESS;
}
		

		


		
				



