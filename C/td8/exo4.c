/*
    triangle de pascal
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <ncurses.h>



/*
	Arguments   : mat as int[][N]
	Consequents	: 	
*/
void init_pascal (int n,int mat[][n]){
	for (int i = 0; i < n+1; ++i)
	{
		mat[i][0]=1;
		for (int j = 1; j < i; ++j)
		{
			mat[i][j]=mat[i-1][j-1]+mat[i-1][j];
		}
		mat[i][i]=1;

	}
}

/*
	Arguments   : mat as int[][]
	Consequents	: 
*/
void affiche_pascal (int n,int mat[][n]){
	for (int i = 0; i < n+1; ++i)
	{
		for (int j = 0; j < i+1; ++j)
		{
			printw(0,i,"%3d ",mat[i][j]);
			getch();
		}
		printf("\n");
		refresh();
	}
}

int main(void){
	initscr();
	int n;
	scanf("%d",&n);
	assert(n>0);
	int mat[n][n];
	//c = getch();
	init_pascal(n,mat);
	affiche_pascal(n,mat);
	endwin() ;
	return EXIT_SUCCESS;
}