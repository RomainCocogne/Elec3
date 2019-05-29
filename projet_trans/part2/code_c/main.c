/*
	programme principal: prend un fichier son en argument et
	affiche la fft en temps reel sous forme graphique
	pour faire le make, commenter l'autre main et decommenter celui-ci

	@authors: Cocogne, Combal, Chbada, El Hachimi
*/
#include "header.h"

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
// 		clock_t begin =clock();
// 		struct timeval tstart, tend;
// 		gettimeofday(&tstart, NULL);
// 		double dataout[SIZE];
// 		if(process_data(dataout,data,readcount,sfinfo->channels,2)) 
// 		{
// 			// printf("\e[;1H\e[2J");
// 			printf("\e[2J");
// 			plot(dataout,SIZE);
// 		}

// 		gettimeofday(&tend, NULL);
// 		long seconds = (tend.tv_sec - tstart.tv_sec);
// 		long micros = ( tend.tv_usec) - (tstart.tv_usec);
// 		clock_t end =clock();
// 		double time_spend= (double)(end-begin)/CLOCKS_PER_SEC;
// 		printf("%ld\n%ld\n",clock(),micros);
// 		sleep_u(23000-micros);
// 	} 

// 	sf_close (file) ;
// } 