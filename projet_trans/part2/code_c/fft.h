/*
	module de fft
	contient plusieurs methodes de calcul de la fft
*/
#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <math.h>


/****************************/
//		  fonctions			//
/****************************/

/*Calcule les expo complexes pour la fft 
Paramètres : 
	- *TW : tableau dans lequel stocker les expo
	- size : taille du tableau 
*/
void twiddle(complex *TW, unsigned int size);

/*FFt en appliquant directement la formule
Paramètres :
	- *data : tableau de complexes , entrée de la FFT
	- *result: tableau de complexes de la même aille que *data , sortie de la FFT
	- size : taille des tableaux *data et *result  
*/
void dft_directe(double *result, double *data, unsigned int size);

/*FFt version recursive. Fonctionne uniquement si size est une puisance de 2
Paramètres :
	- *data : tableau de complexes , entrée de la FFT
	- *result: tableau de complexes de la même aille que *data , sortie de la FFT
	- size : taille des tableaux *data et *result. Doit être une puissance de 2   
*/
void fftrec(complex *data, complex *result, unsigned int size);

/*
Fonction de reverse bit à bit pour la fonction fftiterTW
Paramètres : 
	- input ; nombre à inverser 
	- nbits : sur combien de bits faire le reverse

Exemple : bitrev de 1 sur 4 bits 
		  1 --> sur 4 bits : 0001 --> reverse : 1000 --> 8
		  donc bitrev(1,4) = 8
*/
int bitrev(int inp, int numbits);

/*FFt version iterative avec bit reverse. Fonctionne uniquement si size est une puisance de 2
Paramètres :
	- *data : tableau de complexes , entrée de la FFT et resultat de la FFT
	- size : taille du tableau *data . Doit être une puissance de 2
	- log2n : log2 de la taille du tableau
	- *TW : tableau "tweedle" qui contient les exponentielles
*/
void fftiterTW(complex *data, unsigned int size, int log2n, complex *TW);

/*
	affiche la fft sur stdout
*/
void print_fft(complex *data, int n);
