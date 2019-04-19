#!/bin/bash 

#commande: cca

#$CC $1.c -lsndfile -o compile/$1.o
gcc $1.c -lsndfile -lm -o compile/$1.o

compile/$1.o