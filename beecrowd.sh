#!/bin/bash

if [ $# -lt 1 ]; then
  printf "Usage: ./beecrowd.sh PROBLEM_ID [LANGUAGE=cpp]\n"
  printf "Example: ./beecrowd 1001 c\n"
  exit
fi

id=$1

if [ -z "$2" ]; then
  ext="cpp"
else
  ext=$2
fi

# Create a folder named beecrowd-{i} if it doesn't exist.
if [[ ! -d "beecrowd-$id" ]]; then
  mkdir "beecrowd-$id"
fi

# Create a file named main.{s} in the beecrowd-{i} folder if it doesn't exist.
if [[ ! -f "beecrowd-$id/main.$ext" ]]; then
  touch "beecrowd-$id/main.$ext"
fi

# Create a file named input.txt in the beecrowd-{i} folder if it doesn't exist.
if [[ ! -f "beecrowd-$id/input.txt" ]]; then
  touch "beecrowd-$id/input.txt"
fi
