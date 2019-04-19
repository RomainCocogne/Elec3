
#pragma once


/****************************/
//			types 			//
/****************************/


/****************************/
//		  variables			//
/****************************/


/****************************/
//		  fonctions			//
/****************************/

void twiddle(complex *TW, unsigned int size);
void dft_directe(double *result, double *data, unsigned int size);

void fftrec(complex *data, complex *result, unsigned int size);
int bitrev(int inp, int numbits);
void fftiterTW(complex *data, unsigned int size, int log2n, complex *TW);
void print_fft(complex *data, int n);
