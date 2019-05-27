
#include "header.h"



int main(){

    char c;
    int i=0;
    int j=0;
    int fd;
    struct termios termios_t;
    double mat[BUFFER_LEN];
    int nombre_transmis=0;
    int res;
    sf_count_t frames=1024;
    double data[1024];
    complex dataC[1024];
    twiddle(TW,BUFFER_LEN);
    /* Ouverture de la liaison serie
    ouverture en mode non bloquant, l'apelle de read() en l'abscence de caract reste en attente  */

	if ( (fd=open("/dev/ttyS1",O_RDWR|O_NONBLOCK)) == -1 ) {
		perror("open");
		exit(-1);
	}
 
    /*
* Lecture des parametres courants */
	tcgetattr(fd,&termios_t);
/* On ignore les BREAK et les caracteres avec erreurs de parite */
	termios_t.c_iflag = IGNBRK | IGNPAR;
/* Pas de mode de sortie particulier */
	termios_t.c_oflag = 0;
/* Liaison a 115200 bps avec 8 bits de donnees deux bits de stop  et une parite paire */
	termios_t.c_cflag = B115200 | CS8 | CREAD | CLOCAL;

/* Mode non-canonique avec echo */
	termios_t.c_lflag = ECHO;
/* Caracteres immediatement disponibles avec VMIN la taille du BUFFER de la liaison en serie  */
	termios_t.c_cc[VMIN] = 1;
	termios_t.c_cc[VTIME] = 0;

	termios_t.c_ispeed= B115200;
	cfsetispeed(&termios_t,B115200);
	tcflush(fd,TCIFLUSH);

/* Sauvegarde des nouveaux parametres */
	tcsetattr(fd,TCSANOW,&termios_t);


/* Boucle de lecture des caracteres  */
	while ( 1 ) {

		for(int nombre_transmis=0;nombre_transmis<BUFFER_LEN;nombre_transmis++){
			while((res=read(fd,&c,1))==-1);
		
			mat[nombre_transmis]=(double)(int)c;
					//printf("la matrice %d\n",c);

						
		}
        process_data(data,mat,BUFFER_LEN,1,2);
        printf("\e[2J");
        plot(data,SIZE);
    }
    return EXIT_SUCCESS;
}
		

		


		
				



