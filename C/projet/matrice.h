/*
	header du module du type matrice
*/

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include "carte.h"
/****************************/
//			types 			//
/****************************/

typedef struct 
{
	unsigned int size_x;
	unsigned int size_y;
	//struct element *elt;
	Card **(data);
} Matrice;

/****************************/
//		  variables			//
/****************************/
//extern const Matrice matvide;

/****************************/
//		  fonctions			//
/****************************/
Matrice initMatrice(int n, int m);
extern void delete_matrix(Matrice * mat);
extern void printElement(Card elt);
extern void printMat(Matrice mat);
extern void ajoutElement(Matrice *mat, Card c, int n, int m);
