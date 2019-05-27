#!/bin/bash

name=$1
shift
param=$*
valgrind --leak-check=full compile/$name $param 
