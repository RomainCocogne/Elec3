/*
  implementation des fonctions de plot.h
*/
#include "plot.h"


void plot(double *data, int width, int scale){
  int m;
  int height=47;
  char fene[width][height];
  for (int i=0; i<width; i++){
    m=(int)*(data+i);
    for(int t=0; t<height; t++){
      if (m>=scale*t) fene[i][height-1-t]='#';
      else fene[i][height-1-t]=' ';
      }
    }
  for(int z=0;z<height;z++){
    for(int y=0;y<width;y++){
      printf("%c",fene[y][z]);}
    printf("\n");
  }
}

