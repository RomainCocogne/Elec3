#include <stdio.h>
#include  <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include <complex.h>
#include <math.h>
#include <time.h>
#include "fft.h"
#define BUFFER_LEN 1024



void db(double *n, unsigned int size){
	for(int i=0; i<size; i++){
	    n[i]=20*log10(n[i]);
	}
}

void toComplex (double complex *resultat, double *data, unsigned int size){
	for(int i=0; i<size; i++){
	    *resultat++=CMPLX(*data++,0);
	}
}

void toReal (double *resultat, double complex *data, unsigned int size){
	for(int i=0; i<size; i++){
	    *resultat++=cabs(*data++);
	}
}

double valmax(double *data,int size){
	double max=-70;
	for(int i=0; i<size; i++){
	    if(data[i]>=max)max=data[i];
	}
	return max;
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
	//printf(" %lf ",dft[0]);
	return 0;
} 


void analyseTiming(double *data, int count, int channels){
	for(int mode=0; mode<3; mode++){
		clock_t begin =clock();

	    process_data(data,count,channels,mode);

		clock_t end =clock();
		double time_spend= (double)(end-begin)/CLOCKS_PER_SEC;
		printf("Mode: %d 	time of execution: %lf sec\n",mode,time_spend);
	}
}

int main(int argc, char const *argv[])
{	
	static double data [BUFFER_LEN] ;

	SNDFILE	*file;


	SF_INFO		*sfinfo;
	int			readcount ;
	const char	*filename = "../Ca va mieux en le disant 24.11.2015.wav";
	sfinfo =malloc(sizeof(SF_INFO));

	if (! (file = sf_open (filename, SFM_READ, sfinfo)))
	{	/* Open failed so print an error message. */
		printf ("Not able to open input file %s.\n", filename) ;
		/* Print the error message from libsndfile. */
		puts (sf_strerror (NULL)) ;
		return 1 ;
	}
	//int c=3;
	// while ((readcount = sf_read_double (file, data, BUFFER_LEN)))
	// {	
	// 	process_data (data, readcount, sfinfo->channels) ;
	// 	printf("\n");
	// } 
	readcount=sf_read_double (file, data, BUFFER_LEN);
	sf_close (file) ;
	analyseTiming(data,readcount,sfinfo->channels);
} 


