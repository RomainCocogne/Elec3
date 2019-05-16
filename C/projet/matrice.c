#include "matrice.h"


Matrice initMatrice(int n, int m){
	Matrice mat;
	mat.size_x=n;
	mat.size_y=m;
	mat.data = (void* **)malloc(n * sizeof(void* *)); 
    for (int i=0; i<n; i++) 
         mat.data[i] = (void* *)malloc(m * sizeof(void*)); 
	return mat;
}

void delete_matrix(Matrice * mat){ 
	unsigned int i; 
	for(i=0;i<mat->size_x;++i) 
		free(mat->data[i]); 
	free(mat->data); 
	free(mat); 
} 

void ajoutElement(Matrice *mat, void* c, int n, int m){
	mat->data[n][m]=c;
}