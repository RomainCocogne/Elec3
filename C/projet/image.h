/*
	pris sur http://fvirtman.free.fr/recueil/01_09_02_testbmp.c.php
*/

#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h> 
typedef struct pixel
{
	unsigned char r,g,b;
} pixel;

typedef struct Image
{
	int w,h;
	pixel* dat;
	char *data;
} Image;

Image* Charger(const char* fichier);
int Sauver(Image*,const char* fichier);
Image* NouvelleImage(int w,int h);
Image* CopieImage(Image*);
void SetPixel(Image*,int i,int j,pixel p);
pixel GetPixel_img(Image* I,int i,int j);
void DelImage(Image*);
