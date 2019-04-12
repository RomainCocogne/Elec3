#!/bin/bash

name=$1
shift
param=$*
compile/$name $param
