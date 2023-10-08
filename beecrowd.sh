#!/bin/bash

if [ $# -lt 1 ]; then
  printf "Usage: ./beecrowd.sh PROBLEM_ID\n"
  printf "Example: ./beecrowd 1001\n"
  exit
fi

# Specify the folder name and file path
id=$1
folder_name="beecrowd-$id"
file_path="$folder_name/main.cpp"

# Create a folder named beecrowd-{id} if it doesn't exist.
if [[ ! -d "$folder_name" ]]; then
  mkdir "$folder_name"
fi

# Check if main.cpp doesn't exist in the folder
if [ ! -f "$file_path" ]; then
  # Create main.cpp with the desired content
  echo "#include <iostream>" > "$file_path"
  echo "" >> "$file_path"
  echo "int main() {" >> "$file_path"
  echo "    return 0;" >> "$file_path"
  echo "}" >> "$file_path"
fi

# Create a file named input.txt in the beecrowd-{id} folder if it doesn't exist.
if [[ ! -f "$folder_name/input.txt" ]]; then
  touch "$folder_name/input.txt"
fi
