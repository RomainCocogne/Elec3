/*
	programme principal: prend un fichier son en argument et
	affiche la fft en temps reel sous forme graphique
	pour faire le make, commenter l'autre main et decommenter celui-ci, puis 
	changer le nom de l'executable dans le makefile

	@authors: Cocogne, Combal, Chbada, El Hachimi
*/
#include "header.h"

// /*
// 	arret temporaire du programme
// 	(des taches peuvent tourner en arriere plan)
// 	duree est en microsecondes
// 	On utilise une structure timeval pour faire fonctionner le programme sur la carte atmel
// */
// void sleep_u(long int duree){
//   struct timeval tstart, tend;
//   gettimeofday(&tstart, NULL);
//   long seconds =0;
//   long micros = 0; 
//   while(micros<duree){
//     gettimeofday(&tend, NULL);
//     seconds = (tend.tv_sec - tstart.tv_sec);
//     micros = (seconds*1000000+ tend.tv_usec) - (tstart.tv_usec);
//   }
// }

// int main(int argc, char const *argv[])
// {	
// 	const char *file_name=malloc(sizeof(char)*1000);	
// 	file_name=argv[1];
// 	static double data [BUFFER_LEN] ;	//tableau contenant les 1024 donnees

// //variables pour utiliser le fichier
// 	SNDFILE		*file;
// 	SF_INFO		*sfinfo;
// 	int			readcount ;
// 	const char	*filename = file_name;
// 	sfinfo =malloc(sizeof(SF_INFO));

// //si l'ouverture du fichier rencontre un probleme
// 	if (! (file = sf_open (filename, SFM_READ, sfinfo)))
// 	{
// 		printf ("Not able to open input file %s.\n", filename) ;
// 		puts (sf_strerror (NULL)) ;
// 		return 1 ;
// 	}
// //lecture du fichier
// 	while ((readcount = fx_mix_mono_read_double (file, data, BUFFER_LEN)))
// 	{	
// 		struct timeval tstart, tend;
// 		gettimeofday(&tstart, NULL);
// 		double dataout[SIZE];
// 		if(process_data(dataout,data,readcount,sfinfo->channels,2)) 	//traiter les donnees
// 		{
// 			printf("\e[2J");			//rafraichir l'ecran
// 			plot(dataout,SIZE,1);		//afficher la nouvelle fft
// 		}

// //temporisation pour correspondre au temps reel du son
// 		gettimeofday(&tend, NULL);
// 		long seconds = (tend.tv_sec - tstart.tv_sec);
		
// 		long micros = ( seconds*1000000+ tend.tv_usec) - (tstart.tv_usec);
// 		sleep_u(TIME_BUFFER-micros);	
// 	} 

// 	sf_close (file) ;
// } 