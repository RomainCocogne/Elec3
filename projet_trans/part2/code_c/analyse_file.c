#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include <complex.h>
#include <math.h>
#include <time.h>
#include <ncurses.h>
#include <unistd.h>
#include "fft.h"
#include "plot.h"

#define BUFFER_LEN 1024
#define FILE_NAME file_name
char *file_name="../lapur_400Hz.wav";


void sleep_u(clock_t duree){
	clock_t time_out = clock();
	while((time_out + duree) > clock());
}

/*
	retourne les valeurs de n en db
*/
void db(double *n, unsigned int size){
	for(int i=0; i<size; i++){
	    n[i]=20*log10(n[i]);
	}
}

/*
	transforme un tableau de reels en tableau de complex
*/
void toComplex (double complex *resultat, double *data, unsigned int size){
	for(int i=0; i<size; i++){
	    *resultat++=CMPLX(*data++,0);
	}
}

/*
	transforme un tableau de complex en tableau de reels
*/
void toReal (double *resultat, double complex *data, unsigned int size){
	for(int i=0; i<size; i++){
	    *resultat++=cabs(*data++);
	}
}

int process_data (double *data, int count, int channels, int mode)
{	
	double dft [BUFFER_LEN];
	switch (mode) {
	    case 0: ;
	      	dft_directe(dft,data,BUFFER_LEN);
	      break;
	    case 1: ;
	    	double complex fftrec_crec [BUFFER_LEN];
			double complex data_complex[BUFFER_LEN];
			toComplex(data_complex,data, BUFFER_LEN);
			fftrec(data_complex,fftrec_crec,BUFFER_LEN);
			toReal(dft,fftrec_crec,BUFFER_LEN);
	      break;
	    case 2: ;
	    	double complex data_cbit[BUFFER_LEN];
			toComplex(data_cbit,data, BUFFER_LEN);
	    	complex TW[BUFFER_LEN];
			twiddle(TW,BUFFER_LEN);
			fftiterTW(data_cbit,BUFFER_LEN,10,TW);
			toReal(dft, data_cbit,BUFFER_LEN);
	      break;
	    default:
	    	return 1;
	}
	//printf(" %lf ",dft[100]);
	//db(dft,BUFFER_LEN);
	double *dftbis=dft+20;
	plot(Size,dftbis);
	return 0;
} 


void analyseTiming(double *data, int count, int channels){
	for(int mode=2; mode<3; mode++){
		clock_t begin =clock();

	    process_data(data,count,channels,mode);

		clock_t end =clock();
		double time_spend= (double)(end-begin)/CLOCKS_PER_SEC;
		sleep_u(2300-time_spend*1000);
		clock_t newend =clock();
		double newtime_spend= (double)(newend-begin)/CLOCKS_PER_SEC;
		printf("Mode: %d 	time of execution: %lf sec\n",mode,newtime_spend);
	}
}

int main(int argc, char const *argv[])
{	
	FILE_NAME=argv[1];
	static double data [BUFFER_LEN] ;	//tableau contenant les 1024 donnees

//variables pour utiliser le fichier
	SNDFILE		*file;
	SF_INFO		*sfinfo;
	int			readcount ;
	const char	*filename = FILE_NAME;
	sfinfo =malloc(sizeof(SF_INFO));

//si l'ouverture du fichier rencontre un probleme
	if (! (file = sf_open (filename, SFM_READ, sfinfo)))
	{
		printf ("Not able to open input file %s.\n", filename) ;
		puts (sf_strerror (NULL)) ;
		return 1 ;
	}
//tout le fichier
	while ((readcount = sf_read_double (file, data, BUFFER_LEN)))
	{	
		analyseTiming(data,readcount,sfinfo->channels);
		//printf("\n");
	} 
//une seule itération (1024 elements)
	//readcount=sf_read_double (file, data, BUFFER_LEN);
	sf_close (file) ;
	endwin();
	//analyseTiming(data,readcount,sfinfo->channels);
} 


