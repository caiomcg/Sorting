# Sorting

This repository contains the implementation of various sorting algorithms. Each algorithm is defined as a child of 'sort'
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
Assuming you are in the same directory.

```sh
$ make test
```

Make Test will call the software with multiple test cases.
**To see the results and the input files look at the samples directory.**

Input files are simple txt containing integer numbers. Output files follow the pattern: input_name + algorithm + out.
Eg.: Input: input1.txt; Output: input1.selection.out

## Contributors

* Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
