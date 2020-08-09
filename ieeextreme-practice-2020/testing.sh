#!/bin/bash
GEN=${1?Error: no gen file}
CPP_1=${2?Error: no cpp file}
CPP_2=${3?Error: no cpp comp file}

for((i = 1; i<=100; ++i)); do
    echo "test "$i
    ./$GEN $i > in_t
    ./$CPP_1 < in_t > out_1
    ./$CPP_2 < in_t > out_2
    diff -w out_1 out_2 || break
done

rm in_t out_1 out_2