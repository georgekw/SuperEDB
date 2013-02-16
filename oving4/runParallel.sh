#!/bin/bash
gcc -o parallelVectorSum parallelVectorSum.c -lm -fopenmp
echo parallelVectorSum.c compilation finished
echo ======================================
./parallelVectorSum
