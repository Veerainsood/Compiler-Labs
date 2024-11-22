#!/bin/bash

# Find all .l files and generate corresponding .c files
for file in *.l; do
    lex  "$file" -o "${file%.l}.c" 
done

# Compile .c files into binaries using gcc
for file in *.c; do
    gcc -g -DDEBUG -ll "$file" -o "${file%.c}"
done

# Provide a list of generated binaries
echo "List of generated binaries:"
for file in *; do
    if [ -x "$file" ] && [ ! -d "$file" ]; then
        echo "$file"
    fi
done
