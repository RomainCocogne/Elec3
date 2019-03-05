/*
    matrices identitee
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>


#define N 10

/*
	Arguments   : mat[][] as int tab
	Consequents	: 
*/
void initRandom (int mat[][N]){
	srand(time(NULL));
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			mat[i][j]=rand();
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

/*
	Arguments   : mat as int[][N]
	Consequents	: min
*/
int min (int mat[][N]){
	int min=99999999;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if(mat[i][j] <min){
				min=mat[i][j];
			}
		}
	}
	return min;
}

int main(void){
	int mat[N][N];
	initRandom(mat);
	ecrireMatrice(mat);
	printf("%d\n",min(mat));
	return EXIT_SUCCESS;
}