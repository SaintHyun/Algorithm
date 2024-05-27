#!/bin/bash

find ./build -type f -name "*.out" -exec rm -f {} \;
echo ".out files in the build directory have been deleted."