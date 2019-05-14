/*
	implementation des fonctions de mathematique.h
*/
#include "mathematique.h"

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

void moyenne(double *data, double *result, int sizeinit, int sizefin){
  int fact=sizeinit/sizefin;
  for(int i=0; i<sizefin; i++){
    double val=0;
    for(int f=0; f<fact; f++){
        val+=*data++;
    }
    val=val/fact;
    result[i]=val;
      
  }
}