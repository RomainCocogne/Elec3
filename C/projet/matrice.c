#include "matrice.h"


Matrice initMatrice(int n, int m){
	Matrice mat;
	mat.size_x=n;
	mat.size_y=m;
	mat.data = (Card **)malloc(n * sizeof(Card *)); 
    for (int i=0; i<n; i++) 
         mat.data[i] = (Card *)malloc(m * sizeof(Card)); 
	return mat;
}

void delete_matrix(Matrice * mat){ 
	unsigned int i; 
	for(i=0;i<mat->size_x;++i) 
		free(mat->data[i]); 
	free(mat->data); 
	free(mat); 
} 

void printElement(Card elt){
	printf("%d ", elt.id);
}

void printMat(Matrice mat){
	for (int i = 0; i < mat.size_x; ++i)
	{
		for (int j = 0; j < mat.size_y; ++j)
		{
			printElement(mat.data[i][j]);
		}
		printf("\n");
	}
}

void ajoutElement(Matrice *mat, Card c, int n, int m){
	mat->data[n][m]=c;
}