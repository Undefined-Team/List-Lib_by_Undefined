#!/bin/bash

if [ "$1" != "quick" ]; then
../setup.sh $1 $2
fi
gcc test.c $lib -lud_list -o executable
./executable