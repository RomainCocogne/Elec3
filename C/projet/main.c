/*
    
*/
#include "matrice.h"

int main(int argc, char const *argv[]){
	Matrice mat;
	mat=initMatrice(3,4);
	int k;
	for (int i = 0; i < mat.size_x; ++i)
	{
		for (int j = 0; j < mat.size_y; ++j)
		{
			k=i+j;
			mat.data[i][j].id=k;
		}
	}
	printMat(mat);
	//printElement(mat.data[1][1]);
	return EXIT_SUCCESS;
}