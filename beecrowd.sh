#!/bin/bash

# Create a folder named beecrowd-{i} if it doesn't exist.
if [[ ! -d "beecrowd-$1" ]]; then
  mkdir "beecrowd-$1"
fi

# Create a file named main.{s} in the beecrowd-{i} folder if it doesn't exist.
if [[ ! -f "beecrowd-$1/main.$2" ]]; then
  touch "beecrowd-$1/main.$2"
fi

# Create a file named input.txt in the beecrowd-{i} folder if it doesn't exist.
if [[ ! -f "beecrowd-$1/input.txt" ]]; then
  touch "beecrowd-$1/input.txt"
fi
