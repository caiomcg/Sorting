# Sorting

This repository contains the implementation of various sorting algorithms. Each algorithm is defined as a child of 'sort',
which defines time related features.

## Requirements
- [GNU GCC version 5.4.0 or above](https://gcc.gnu.org/)
- [GNU Make 4.1 or above](https://www.gnu.org/software/make/)

## Cloning

```sh
$ git clone https://github.com/caiomcg/Sorting
$ cd Sorting/
```
## Compiling
Assuming you are in the same directory, simply invoke make

```sh
$ make
```

## Testing
```sh
$ make test
```
### Test results

Make Test will call the software with multiple test cases.
**To see the results and the input files look at the samples directory.**

Input files are simple .txt containing integer numbers. Output files follow the pattern: input_name + algorithm + out.

Eg.: Input: input1.txt; Output: input1.selection.out

### Cleaning the test
'cleantest' will get rid of all .out files in the samples folder

```sh
$ make cleantest
```

### Custom test
Custom tests can be done by calling the executable directly. By typing Sorting, you will be prompted with the options
supported by the software. 

```sh
$ ./bin/Sorting
NAME
        Sorting - Sorting algorithms written in C++.
SYNOPSIS
        Sorting [INPUT_FILE] [ALGORITHM]
DESCRIPTION
        Sort a file with the specified sorting algorithm.
        [INPUT_FILE]
            File to be sorted
        [ALGORITHM]
            Sort with the specified algorith:
            S - Selection Sort
            I - Insertion Sort
            M - Merge Sort
            Q - Quick Sort
            H - Heap Sort
            A - All algorithms
EXIT STATUS
        0 - If ok
        1 - If a problem occured
USE EXAMPLE
        Sorting input.txt A
```

#### Testing a single algorithm
Eg.: Testing Insertion Sort

```sh
$ ./bin/Sorting input.txt I # the last argument is the desired algorithm
```

#### Testing all algorithms
A as the last argument indicates that all the algorithms should be tested

```sh
$ ./bin/Sorting input.txt A
```

## Generating test files
Accompaning the sorting algorithms, is a simple python implementation that generate a file with 'n' numbers randomized between
0 and 1000.

### Usage
Invoke the script

```sh
$ python generate_random.py output.txt 10000 # The last argument indicate the amount of random numbers to dump
```

## Contributors

* Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
