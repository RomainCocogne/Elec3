/*
    carré magique impair
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

#define N 5

void initCarreMagique(int cmagique [][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cmagique[i][j]=0;
		}
	}
}
void afficherCarreMagique(int cmagique [][N]){
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			printf("%2d  ",cmagique[i][j]);
		}
		printf("\n");
	}
}

void calculerCarreMagique(int cmagique [][N]){
	int i=1;
	int x=(int)N/2+1;
	int y=(int)N/2;
	for (int a = 0; a < N*N; ++a)
	{
		if(x==N) x=0;
		if(y==N) y=0;
		if(cmagique[x][y] != 0){
			if(y==0) y=N-1;
			else --y;
			if(x==N-1) x=0;
			else ++x;
			
		}
		cmagique[x++][y++]=i++;
	}
}

int verifierCarre(int cmagique [][N]){
	int rescol=0, reslig=0, resdiag=0;
	int res=0;
	for (int i = 0; i < N; ++i)
		res+=cmagique[i][0];
	for (int i = 0; i < N; ++i)
	{
		reslig=0;
		for (int j = 0; j < N; ++j)
		{
			reslig+=cmagique[i][j];
			if(i==j)
				resdiag+=cmagique[i][j];
		}
		if(reslig!=res) return 0;
	}
	if(resdiag!=res) return 0;
	resdiag=0;
	for (int i = 0; i < N; ++i)
	{
		rescol=0;
		for (int j = 0; j < N; ++j)
		{
			rescol+=cmagique[j][i];
			if(N-1-j==i)
				resdiag+=cmagique[i][j];
		}
		if(rescol!=res) return 0;
	}
	if(resdiag!=res) return 0;

	return 1;
}

int main(void){
	int carreMagique [N][N];
	assert((N&1));
	initCarreMagique(carreMagique);
	calculerCarreMagique(carreMagique);
	if(verifierCarre(carreMagique))
		afficherCarreMagique(carreMagique);
	return EXIT_SUCCESS;
}