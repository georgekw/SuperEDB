#!/bin/bash
mpicc -o mpiVectorSum mpiVectorSum.c -lm -fopenmp -std=c99
echo mpiVectorSum.c compilation finished
echo ======================================
mpirun -np 4 ./mpiVectorSum