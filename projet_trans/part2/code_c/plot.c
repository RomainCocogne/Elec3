/*
  implementation des fonctions de plot.h
*/
#include "plot.h"


void sleep_u(long int duree){
  struct timeval tstart, tend;
  gettimeofday(&tstart, NULL);
  long seconds =0;
  long micros = 0;

  while(tend.tv_usec-tstart.tv_usec<duree){
    gettimeofday(&tend, NULL);
    // seconds = (tend.tv_sec - tstart.tv_sec);
    // micros = (seconds*1000000+ tend.tv_usec) - (tstart.tv_usec);
    printf("%ld\n",micros); 
  }
  // clock_t time_out = clock();
  // while((time_out + duree) > clock());
}


void plot(double *data, int width){
  int m, scale=120;
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

