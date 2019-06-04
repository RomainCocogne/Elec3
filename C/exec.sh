#!/bin/bash

name=$1
shift
param=$*
if [[ $1 == "-v" ]]; then
	shift
	valgrind --leak-check=full --track-origins=yes compile/$name $param 
else 
	compile/$name $param 
fi
