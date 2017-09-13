/**
 * @file main.cpp
 *
 * @brief The main thread that test the algorithms
 *
 * @license
 * 
 * MIT License
 * 
 * Copyright (c) 2017 Caio Marcelo Campoy Guedes
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * 
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 *
 * @author Caio Marcelo Campoy Guedes <caiomcg@gmail.com>
 */

#include <iostream> // C++ standart I/O
#include <vector>   // STL Vector

#include "SelectionSort.h" // Selection Sort
#include "InsertionSort.h" // Insertion Sort
#include "MergeSort.h"     // Merge Sort
#include "QuickSort.h"     // Quick Sort
#include "HeapSort.h"      // Heap Sort
#include "CountingSort.h"  // Counting Sort
#include "RadixSort.h"     // Radix Sort

/**
 * @brief Diplay the software usage
 */
void usage (void) {
    std::cout << "\033[1;37mNAME\033[0m" << std::endl;
    std::cout << "        Sorting - Sorting algorithms written in C++." << std::endl;
    std::cout << "\033[1;37mSYNOPSIS\033[0m" << std::endl;
    std::cout << "        Sorting [INPUT_FILE] [ALGORITHM]" << std::endl;
    std::cout << "\033[1;37mDESCRIPTION\033[0m" << std::endl;
    std::cout << "        Sort a file with the specified sorting algorithm." << std::endl;
    std::cout << "        [INPUT_FILE]" << std::endl;
    std::cout << "            File to be sorted"  << std::endl;
    std::cout << "        [ALGORITHM]" << std::endl;
    std::cout << "            Sort with the specified algorith:"  << std::endl;
    std::cout << "            S - Selection Sort"  << std::endl;
    std::cout << "            I - Insertion Sort"  << std::endl;
    std::cout << "            M - Merge Sort"  << std::endl;
    std::cout << "            Q - Quick Sort"  << std::endl;
    std::cout << "            H - Heap Sort"  << std::endl;
    std::cout << "            C - Counting Sort"  << std::endl;
    std::cout << "            R - Radix Sort"  << std::endl;
    std::cout << "            A - All algorithms"  << std::endl;
    std::cout << "\033[1;37mEXIT STATUS\033[0m" << std::endl;
    std::cout << "        0 - If ok" << std::endl;
    std::cout << "        1 - If a problem occured" << std::endl;
    std::cout << "\033[1;37mUSE EXAMPLE\033[0m" << std::endl;
    std::cout << "        \033[1;35mSorting input.txt A\033[0m" << std::endl;
}


int main(int argc, char** argv) {

    if (argc < 2) { // Check if the amount of parameters passed is correct
        usage();    // Print the usage
        return 1;   // Stop the process
    }

    std::vector<Sort<int>*> sorting_algorithms; // Store the algorithms used

    if (std::string(argv[2]) == "S" || std::string(argv[2]) == "A") { // Check if should use Selection Sort
        sorting_algorithms.push_back(new SelectionSort<int>{}); // Add the sorting algorithm to the vector 
    }
    if (std::string(argv[2]) == "I"  || std::string(argv[2]) == "A") { // Check if shoul use Insertion Sort
        sorting_algorithms.push_back(new InsertionSort<int>{}); // Add the sorting algorithm to the vector
    }
    if (std::string(argv[2]) == "Q"  || std::string(argv[2]) == "A") { // Check if shoul use Quick Sort
        sorting_algorithms.push_back(new QuickSort<int>{}); // Add the sorting algorithm to the vector
    }
    if (std::string(argv[2]) == "M"  || std::string(argv[2]) == "A") { // Check if shoul use Merge Sort
        sorting_algorithms.push_back(new MergeSort<int>{}); // Add the sorting algorithm to the vector
    }
    if (std::string(argv[2]) == "H"  || std::string(argv[2]) == "A") { // Check if shoul use Heap Sort
        sorting_algorithms.push_back(new HeapSort<int>{}); // Add the sorting algorithm to the vector
    }
    if (std::string(argv[2]) == "C"  || std::string(argv[2]) == "A") { // Check if shoul use Heap Sort
        sorting_algorithms.push_back(new CountingSort<int>{}); // Add the sorting algorithm to the vector
    }
    if (std::string(argv[2]) == "R"  || std::string(argv[2]) == "A") { // Check if shoul use Heap Sort
        sorting_algorithms.push_back(new RadixSort<int>{}); // Add the sorting algorithm to the vector
    }

    for (auto sort : sorting_algorithms) { // Iterate through the sorting algorithms
        sort->test(argv[1], [](int& first, int& last) -> bool { // Invoke the test: Sorting + Outputting to file + Estimated time spent
            return first > last ? true : false; // Sort from lowest to biggest
        });
        delete sort; // Dealloc the algorithm
    }

    sorting_algorithms.clear(); // Clear the vector;

    return 0; // Correctly ends the process
}