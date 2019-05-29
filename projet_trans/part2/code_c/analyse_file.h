/*
	module qui regroupe les fonctions d'analyse d'un fichier son
	utilise tout les autres modules 
*/

#pragma once

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include "mathematique.h"
#include "fft.h"
#include "plot.h"

/****************************/
//		  variables			//
/****************************/
#define BUFFER_LEN 1024
#define TIME_BUFFER BUFFER_LEN/44.1 //freq d'echantillonnage de 44.1kHz pour les .wav
/****************************/
//		  fonctions			//
/****************************/
/*
	extrait les donnees d'un fichier sous forme de doubles
	par frames de datalen
	(gere le mono et le stereo)
*/
sf_count_t fx_mix_mono_read_double (SNDFILE *file, double *data, sf_count_t datalen);

/*
	traite les donnees extraites du fichier
	gere la fft et l'affichage
*/
int process_data (double *res, double *data, int count, int channels, int mode);

/*
	pour tester l'efficacite des differents algo de fft
*/
void analyseTiming(double *data, int count, int channels);
