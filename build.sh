#!/bin/bash

gcc -o run run.c func.c
gcc -o run2 run2.c func.c
gcc -o measure_sys measuresyscall.c func.c
gcc fast.c -o fast
gcc fast_noxor.c -o fast_noxor
