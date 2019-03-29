#!/bin/bash

arm-none-eabi-as -g -o compiles/$1.o scripts/$1.s
arm-none-eabi-ld -o applis/$1.elf compiles/$1.o
	