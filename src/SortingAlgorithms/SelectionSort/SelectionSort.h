/**
 * @file SelectionSort.h
 *
 * @class SelectionSort
 *
 * @brief Selections sort implementation
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

#ifndef SORTING_ALGORITHMS_SELECTION_SORT_H
#define SORTING_ALGORITHMS_SELECTION_SORT_H

#include "Sort.h"

template <typename T> // Defines the class as a template
class SelectionSort : public Sort<T> { // Defines the class
public:
    /**
     * @brief Default constructor
     */
    SelectionSort() {}

    /**
     * @brief Define how Selection Sort behaves
     * 
     * @param arr The array to be sorted
     * @param size The size of the array
     * @param order_function The function that defines how the ordering will be done
     */
    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        this->startTimer();  // Stores the start time of the sorting

        for (unsigned i = 0; i < size; i++) { // Iterate throug the array
            unsigned current_location = i; // Store the initial location of the biggest/smallest number
            for (unsigned j = i + 1; j < size; j++) { // Iterate from the picked position
                if (order_function(arr[current_location], arr[j])) { // Verify if the best value should be swapped 
                    current_location = j; // Store the best value position
                }
            }
            this->swap(arr[current_location], arr[i]); // Swap the best value with the last searched index
        }
        
        this->stopTimer(); // Stores the time at the end of the sorting
    }

};

#endif // define SORTING_ALGORITHMS_SELECTION_SORT_H