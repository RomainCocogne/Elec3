#!/bin/bash

name=$1
shift
param=$*
valgrind --leak-check=full --track-origins=yes compile/$name $param 
