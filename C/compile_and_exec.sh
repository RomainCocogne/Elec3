#!/bin/bash

gcc -Wall -pedantic -o compile/$1 $1.c -lm -lncurses
compile/$1