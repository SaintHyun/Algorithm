#!/bin/bash

if [ "$#" -ne 1 ]; then
  echo "Usage: ./run.sh <source_file.cpp>"
  exit 1
fi

filename=$(basename -- "$1")
filename="${filename%.*}"

echo "g++ -Wall -std=gnu++17 "$1" -o "build/$filename.out""
g++ -Wall -std=gnu++17 "$1" -o "build/$filename.out"

if [ $? -eq 0 ]; then
  echo "Running Program"
  echo ""
  ./"build/$filename.out"
  echo ""
  echo "Program is terminated"
else
  echo "Compile Error"
fi
