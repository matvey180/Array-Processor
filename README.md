# Array Processor

A C++ program that reads data from a file, processes arrays, and performs various calculations including summing positive elements, creating a new array with cumulative sums, and finding the element with the smallest absolute value.

## Description

This program reads a parameter N and an array of 10 floating-point numbers from a file named "data.txt". It then performs the following operations:

1. Creates a new array NEWVEC based on the original array VEC
2. Calculates the sum of all positive elements from the original array
3. Computes cumulative sums for array elements
4. Calculates the sum of the first N elements of the new array
5. Finds the element with the smallest absolute value and its index

## Input File Format

The program expects a file named `data.txt` with the following format:
- First line: a number N (1 ≤ N ≤ 10, integer)
- Next 10 lines: floating-point numbers (the array elements)

Example `data.txt`:
