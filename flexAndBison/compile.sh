#!/bin/bash

#compile script

echo "Compiling Bison and Flex"
#rm *.c *.h ctcpd
yacc -d bison.y
flex --header=flex.h flex.l

gcc6 lex.yy.c bison.tab.c -o ctcpd -O2 -Wl,-rpath=/usr/local/lib/gcc6 -Wno-hsa -fopenmp-simd -fopenacc -fopenmp -fno-asm  -fno-builtin -fno-builtin-function -O3 -Wall
#--enable-offload-targets=hsa
