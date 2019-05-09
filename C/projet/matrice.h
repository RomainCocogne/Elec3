/*
	header du module du type matrice
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#pragma once


/****************************/
//			types 			//
/****************************/
typedef struct{
	int id,mode,posX,posY;
	} Card;

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
void delete_matrix(Matrice * mat);
void printElement(Card elt);
void printMat(Matrice mat);
void ajoutElement(Matrice *mat, Card c, int n, int m);