#!/bin/bash

# Define the path to your application executable
APP_PATH="./pb2"

# Define the directory where the input files are located
INPUT_DIR="./checker/private_tests/p2/input"

# Define the directory where the output files should be stored
OUTPUT_DIR="./checker/private_tests/p2/out"

# Iterate over the input files test1.in to test10.in
for ((i=1; i<=10; i++)); do
    # Construct the input file name
    input_file="$INPUT_DIR/test${i}.in"

    

    # Check if the input file exists

        # Run the application with the input file
        # Copy the contents of the input file to data.in
        cp "$input_file" date.in

        "$APP_PATH"
        
        # Optionally, you can compare the output file with an expected output
        # and print the result
        expected_output="./checker/private_tests/p2/ref/test${i}.ref"
        generated_output="date.out"
        diff_output=$(diff "$expected_output" "$generated_output")

        if [ -z "$diff_output" ]; then
            echo "Test ${i}: Passed"
        else
            echo "Test ${i}: Failed"
            echo "Diff:"
            echo "$diff_output"
        fi
    
done