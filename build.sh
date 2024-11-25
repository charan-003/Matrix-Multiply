#!/bin/bash

# Variables
SOURCE="matrix_multiply.cpp"
OUTPUT="matrix_multiply"
OMP_FLAGS="-fopenmp"

# Step 1: Compile
echo "Compiling $SOURCE with g++-14..."
g++-14 $SOURCE -o $OUTPUT $OMP_FLAGS
if [ $? -ne 0 ]; then
    echo "Compilation failed!"
    exit 1
fi
echo "Compilation successful!"

# Step 2: Run Tests
echo "Running program..."
for size in 100 200 500; do
    echo "Matrix size: $size"
    echo $size | ./$OUTPUT >> results.log
done
echo "Tests completed. Results stored in results.log."
