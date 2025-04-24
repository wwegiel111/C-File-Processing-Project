# C File Processing Project

## Overview
This project demonstrates file processing in C. It includes programs to:
1. Calculate the sum of numbers in a file where the first number specifies the quantity of numbers to sum.
2. Process a gradebook file to filter marks within a specific range and create individual files for each surname.

## Files
- `main5.c`: Contains the implementation for summing numbers in a file (`number_inputs.txt`).
- `main7.c`: (Currently empty) Can be used for additional functionality.
- `number_inputs.txt`: Input file for `main5.c`. The first number specifies the quantity of numbers, followed by the numbers to sum.
- `gradebook.txt`: Input file containing surnames and their associated marks.
- `test.txt`: Example file for testing error handling.

## How It Works
### `main5.c`
1. Reads the first number from `number_inputs.txt` as the quantity of numbers.
2. Sums the specified number of integers.
3. Validates that the count of numbers matches the quantity.
4. Outputs the sum or an error message if the file format is invalid.

### `gradebook.txt` Processing
1. Reads surnames and their associated marks.
2. Filters marks in the range [2, 5].
3. Creates a new file for each surname containing the filtered marks.

## Input File Formats
### `number_inputs.txt`
Example:
5 10 20 30 40 50

- The first number (`5`) specifies the quantity of numbers.
- The program sums the next 5 numbers (`10 + 20 + 30 + 40 + 50 = 150`).

### `gradebook.txt`
Example:
Smith 5 2 4 5 
Johnson 5 5 3 2 
Williams 5 2 2 4 
Brown 5 3 3 3 
Jones 2 3 5 2

- Each line starts with a surname followed by marks.
- Marks in the range [2, 5] are written to `<surname>.txt`.
