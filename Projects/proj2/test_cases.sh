cat << 'EOF' > run_p2_tests.sh
#!/bin/bash

# 1. Compile the code for Phase 2
echo "Compiling p2_2.c and sparse_2.c..."
gcc p2_2.c sparse_2.c -o a.out

if [ $? -ne 0 ]; then
    echo "Compilation failed! Please check your C code."
    exit 1
fi

echo "Compilation successful."
echo "---------------------------------------------------"

# 2. Gather ONLY s_in_*.txt and l_in_*.txt input files
readarray -t files < <(find . -maxdepth 1 -type f \( -name "s_in_*.txt" -o -name "l_in_*.txt" \) -printf "%P\n" | sort)

num_files=${#files[@]}

if [ "$num_files" -lt 2 ]; then
    echo "Found less than 2 valid files. Not enough to make combinations. Exiting."
    exit 1
fi

echo "Found $num_files valid test files. Starting combination tests..."

# 3. Create a directory to hold all the individual result files
mkdir -p test_results

# 4. Loop through combinations
for (( i=0; i<num_files; i++ )); do
    for (( j=i+1; j<num_files; j++ )); do
        
        file1="${files[$i]}"
        file2="${files[$j]}"
        
        out_file="test_results/out_${file1%.txt}_${file2%.txt}.txt"

        echo "Running: ./a.out $file1 $file2 $out_file"
        
        # ---------------------------------------------------------
        # THE FIX: Automatically pipe coordinates into the program
        # "1 1 2 2" represents start (1,1) and end (2,2)
        # ---------------------------------------------------------
        echo "1 1 2 2" | ./a.out "$file1" "$file2" "$out_file"
        
    done
done

echo "---------------------------------------------------"
echo "All test combinations completed!"
echo "Check the 'test_results' directory for the output files."
EOF

chmod +x run_p2_tests.sh
./run_p2_tests.sh