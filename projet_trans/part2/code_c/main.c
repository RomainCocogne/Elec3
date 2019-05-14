/*
	programme principal: prend un fichier son en argument et
	affiche la fft en temps reel sous forme graphique
*/
#include "header.h"

int main(int argc, char const *argv[])
{	
	const char *file_name=malloc(sizeof(char)*1000);	
	file_name=argv[1];
	static double data [BUFFER_LEN] ;	//tableau contenant les 1024 donnees

//variables pour utiliser le fichier
	SNDFILE		*file;
	SF_INFO		*sfinfo;
	int			readcount ;
	const char	*filename = file_name;
	sfinfo =malloc(sizeof(SF_INFO));

//si l'ouverture du fichier rencontre un probleme
	if (! (file = sf_open (filename, SFM_READ, sfinfo)))
	{
		printf ("Not able to open input file %s.\n", filename) ;
		puts (sf_strerror (NULL)) ;
		return 1 ;
	}
//lecture du fichier
	while ((readcount = fx_mix_mono_read_double (file, data, BUFFER_LEN)))
	{	
		clock_t begin =clock();

		double dataout[SIZE];
		if(process_data(dataout,data,readcount,sfinfo->channels,2)) plot(dataout,SIZE);

		clock_t end =clock();
		double time_spend= (double)(end-begin)/CLOCKS_PER_SEC;
		sleep_u(23000-10000*time_spend);
		system("clear");
	} 

	sf_close (file) ;
	endwin();
} 