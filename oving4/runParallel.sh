#!/bin/bash
gcc -o parallelVectorSum parallelVectorSum.c -lm -fopenmp -std=c99
echo parallelVectorSum.c compilation finished
echo ======================================
./parallelVectorSum
