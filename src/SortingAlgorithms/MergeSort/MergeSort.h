/**
 * @file MergeSort.h
 *
 * @class MergeSort
 *
 * @brief Merge sort implementation
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

#ifndef SORTING_ALGORITHMS_MERGE_SORT_H
#define SORTING_ALGORITHMS_MERGE_SORT_H

#include "Sort.h" // Sort base class
 
template <typename T> // Defines the class as a template
class MergeSort : public Sort<T> { // Defines the class
public:
    /**
    * @brief Default constructor
    */
     MergeSort() {}

    /**
    * @brief Merge the array
    * 
    * @param arr Array to be merged
    * @param initial Initial array position
    * @param mid_point Merge mid point for the partition
    * @param final Final array position
    */
    void merge(T* arr, int initial, int mid_point, int final_chunck) {
        int left_reference = 0;        // Reference to the elements of the array
        int right_reference = 0;       // Reference to the elements of the array
        int merge_reference = initial; // Reference to the elements of the array 

        int left_size = mid_point - initial + 1;
        int right_size = final_chunck - mid_point;

        T* left  = new T[left_size];  // Create temporary arrays
        T* right = new T[right_size]; // Create temporary arrays

        for (int i = 0; i < left_size; i++) { // Copy the left side
            left[i] = arr[initial + i];
        }

        for (int i = 0; i < right_size; i++) { // Copy the right side
            right[i] = arr[mid_point + 1 + i];
        }

        while (left_reference < left_size && right_reference < right_size) {  // Proceed until we reach the end of one of the arrays
            if (left[left_reference] <= right[right_reference]) { // if data in the left position is smaller we move it to the mid point reference
                arr[merge_reference] = left[left_reference];
                left_reference++;
            } else {
                arr[merge_reference] = right[right_reference]; // Right reference is smaller
                right_reference++;
            }
            merge_reference++;
        }

        while (left_reference < left_size) { // Empty all remaining numbers
            arr[merge_reference] = left[left_reference];
            left_reference++;
            merge_reference++;
        }
        
        while (right_reference < right_size) { // Empty all remaining numbers
            arr[merge_reference] = right[right_reference];
            right_reference++;
            merge_reference++;
        }

        delete left;  // Free the data
        delete right; // Free the data
    }

    /**
     * @brief Call Merge Sort recursively
     * @details Split the array until only one element is present on the last recursion
     * 
     * @param arr Data to be sorted
     * @param initial Initial position of the array
     * @param final_chunck Final position of the array
     */
    void mergeSort(T* arr, int initial, int final_chunck) {
        if (initial < final_chunck) { // As long as we do not have only one element execute
            int mid_point = (initial + final_chunck) / 2; // Calculate the mid point
        
            mergeSort(arr, initial, mid_point); // Call Merge Sort to the left side
            mergeSort(arr, mid_point+1, final_chunck); // Call Merge Sort to the right side
            merge(arr, initial, mid_point, final_chunck); // Merge the array
        }
     }
 
    /**
    * @brief Define how Merge Sort behaves
    * 
    * @param arr The array to be sorted
    * @param size The size of the array
    * @param order_function The function that defines how the ordering will be done
    */
    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        this->startTimer(); // Stores the start time of the sorting
        this->mergeSort(arr, 0, size);
        this->stopTimer(); // Stores the time at the end of the sorting
    }
    /**
    * @brief Test the algorithm
    * 
    * @param input Input to be sorted
    * @param order_function The function that defines how the ordering will be done
    */
    void test(std::string input, std::function<bool(T& first, T& last)> order_function) {
        T* data = nullptr; // Pointer to the data fetched from the input
        long data_size = this->file_handler_->fetchInput(input, &data); // Fetch from the input
        if (data_size == 0) { // If no data on the file we stop the process
            if (data != nullptr) delete data; // Free the data buffer
            std::clog << "\033[1;30mInvalid input. Terminating\033[0m" << std::endl;
            return; // Stop the test
        }
        
        input.erase(input.find('.', 1)); // Format the output
        std::clog << "\033[1;37mMerge Sort:\033[0m" << std::endl;
        std::clog << "\033[1;35m\tOutputing to: " << input + ".merge.out\033[0m" << std::endl;
        
        this->sort(data, data_size, order_function); // Sort the data
        
        std::clog << "\033[1;35m\tProcessing time: " << this->getElapsed() << " seconds\033[0m" << std::endl;

        this->file_handler_->writeToOutput(input + ".merge.out", data, data_size); // Write to the output file
        delete data; // Free the data
    }
};
 
 
 #endif // define SORTING_ALGORITHMS_MERGE_SORT_H
 