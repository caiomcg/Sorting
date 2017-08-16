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

#include <iostream>

#include "SelectionSort.h"
#include "InsertionSort.h"

int main(int argc, char** argv) {
    InsertionSort<int> selection_sort;
    int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    std::cout << "Before selection: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";

    selection_sort.sort(arr, 10, [](int& first, int& last) -> bool {
        return first > last ? true : false;
    });

    std::cout << "After selection: ";
    for (int i = 0; i < 10; i++) {
        std::cout << arr[i] << " ";
    }

    std::cout << "\nElapsed time: " << selection_sort.getElapsed() << "s" << std::endl;
    std::cout << "\n";
    return 0;
}