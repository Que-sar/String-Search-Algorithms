#!/bin/bash

#faster.sh (size of string to create) (mainf.cpp to compile) (kmp.cpp to compile) (bmh.cpp to compile) (amount of times to run the executable for testing)

python3 createstrings.py $1;
rm a.out;
g++ $2 $3 $4 -o executablefile;

for (( c=1; c<=$5; c++ ))
do
    ./executablefile;
done
