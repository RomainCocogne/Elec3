#!/bin/bash

gcc -Wall -pedantic -o compile/$1 $1.c -lm -lncurses

name=$1
shift
param=$*
compile/$name $param