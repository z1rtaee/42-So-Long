#!/bin/bash

for file in *.png
do
    name=$(basename "$file" .png)
    convert "$file" "$name.xpm"
    rm -rf *.png
    echo "Converted $file -> $name.xpm"
done