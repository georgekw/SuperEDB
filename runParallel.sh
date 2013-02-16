#!/bin/bash
gcc -o parallelVectorSum parallelVectorSum.c -lm
echo parallelVectorSum.c compilation finished
echo ======================================
./parallelVectorSum
