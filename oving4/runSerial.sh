#!/bin/bash
gcc -o serialVectorSum serialVectorSum.c -lm -std=c99
echo serialVectorSum.c compilation finished
echo ======================================
./serialVectorSum
