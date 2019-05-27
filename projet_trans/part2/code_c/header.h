/*
	regroupe tout les modules
*/

#include <termios.h>// pour la transmission en serie 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sndfile.h>
#include <complex.h>
#include <math.h>
#include <time.h>
#include <sys/time.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include "fft.h"
#include "plot.h"
#include "mathematique.h"
#include "analyse_file.h"


// #define _DEFAULT_SOURCE //for usleep 
#define SWAP(a,b) ctmp=(a); (a)=(b); (b)=ctmp
#define M_PI       3.14159265358979323846
#define T 500000
static complex TW[BUFFER_LEN];