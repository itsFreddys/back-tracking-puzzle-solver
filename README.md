# BackTracking Puzzle Solver

This program implements a backtracking recursive algorithm to solve a summation puzzle.

The puzzle consists of three strings representing digits (letters). The goal is to assign unique digit values (0-9) to each letter in the strings such that the sum represented by the first two strings equals the sum represented by the third string.

For example:

Input: SEND + MORE = MONEY
Output: (S=9, E=5, N=6, D=7, M=1, O=0, R=8, Y=3)


Where behind the scenes the structure would be trying different combinations of numbers to characters until a solution is found.
