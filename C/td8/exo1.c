/*
    matrices identitee
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define N 10

/*
	Arguments   : mat[][] as int tab
	Consequents	: 
*/
void identite (int mat[][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (i==j)
				mat[i][j]=1;
			else
				mat[i][j]=0;
		}
	}
}

/*
	Arguments   : mat as int[][]
	Consequents	: 
*/
void ecrireMatrice (int mat[][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%d  ",mat[j][i]);
		}
		printf("\n");
	}
}

int main(void){
	int mat[N][N];
	identite(mat);
	ecrireMatrice(mat);
	return EXIT_SUCCESS;
}