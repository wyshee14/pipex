#!/bin/bash

# Create input file
echo -e "info: System started\nerror: Disk full\nwarning: High memory usage\nerror: File not found" > input.txt

# Run Pipex
./pipex input.txt "grep error" "sort" output.txt

# Compare with Bash output
cat input.txt | grep "error" | sort > expected_output.txt

# Check if output matches
if diff -q output.txt expected_output.txt > /dev/null; then
    echo "✅ Test Passed!"
else
    echo "❌ Test Failed!"
    echo "Expected:"
    cat expected_output.txt
    echo "Got:"
    cat output.txt
fi
