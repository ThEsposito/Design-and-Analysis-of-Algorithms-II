cmake_minimum_required(VERSION 4.1)
project(Design_and_Analysis_of_Algorithms C)

set(CMAKE_C_STANDARD 11)

# Backtracking
add_executable(ex1_binary_sequences backtracking/ex1_binary_sequences.c)
add_executable(ex2_permutation backtracking/ex2_permutation.c)
add_executable(ex3_score_sequences backtracking/ex3_score_sequences.c)
add_executable(ex4_sorting backtracking/ex4_sorting.c)
add_executable(ex5_max_permutation_sum backtracking/ex5_max_permutation_sum.c)
add_executable(ex6_subset_sum backtracking/ex6_subset_sum.c)
add_executable(sudoku backtracking/sudoku.c)

# Brute force
add_executable(brute_ex5 brute-force/ex5.c)
add_executable(brute_ex6 brute-force/ex6.c)