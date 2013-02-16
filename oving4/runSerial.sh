#!/bin/bash
gcc -o serialVectorSum serialVectorSum.c -lm
echo serialVectorSum.c compilation finished
echo ======================================
./serialVectorSum
