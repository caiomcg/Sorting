/**
 * @file CountingSort.h
 *
 * @class CountingSort
 *
 * @brief Counting sort implementation
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

#ifndef SORTING_ALGORITHMS_COUNTING_SORT_H
#define SORTING_ALGORITHMS_COUNTING_SORT_H

#include "Sort.h" // Sort base class

template <typename T> // Defines the class as a template
class CountingSort : public Sort<T> { // Defines the class
public:
    /**
    * @brief Default constructor
    */
    CountingSort() {}

    /**
     * @brief Search for the biggest element in the array
     * 
     * @param arr Array to be searched
     * @param size Size of the array
     * 
     * @return The biggest element
     */
    int findMaxNumber(T* arr, const unsigned& size) {
        T max = arr[0]; // Store the Maximum number

        for (unsigned i = 1; i < size; i++) { // Iterate through the elements
            if (max < arr[i]) { // Chekc if there is a bigger one
                max = arr[i]; // Add it as max
            }
        }
        return max; // Return the maximum number
    }

    /**
     * @brief Counting Sort implementation
     * 
     * @param arr Array to be sorted
     * @param size Size of the array
     * @param max_num Biggest number of the array
     */
    void countingSort(T* arr, const unsigned& size, T max_num) {
        T* counterArray = new T[max_num](); // Array that count the elements
        T* sorted = new T[size](); // Sorted Array

        for (int i = 0; i < size; i++) {
            counterArray[arr[i] - 1] += 1; // Count the elements
        }
        
        for (int i = 1; i < max_num; i++) {
            counterArray[i] += counterArray[i-1]; // Reorder the numbers
        }
        
        for (int i = 0; i < size; i++) {
            sorted[counterArray[arr[i] -1] -1] = arr[i]; // Sort the array
            counterArray[arr[i] -1]--;  // Remove one element that was added to the sorted one
        }
    
        for (int i = 0; i < size; i++) {
        		arr[i] = sorted[i]; // Copy to the original input
        }
    
        delete sorted;       // Free the pointers
        delete counterArray; // Free the pointers
    }

    /**
    * @brief Define how Heap Sort behaves
    * 
    * @param arr The array to be sorteds
    * @param size The size of the array
    * @param order_function The function that defines how the ordering will be done
    */
    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        T max = this->findMaxNumber(arr, size); // Find the biggest number in the array(We do not consider this part of the sorting algorithm)

        this->startTimer(); // Stores the start time of the sorting

        this->countingSort(arr, size, max);
    
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
        std::size_t data_size = this->file_handler_->fetchInput(input, &data); // Fetch from the input
        
        if (data_size == 0) { // If no data on the file we stop the process
            if (data != nullptr) delete data; // Free the data buffer
            std::clog << "\033[1;30mInvalid input. Terminating\033[0m" << std::endl;
            return; // Stop the test
        }
        
        input.erase(input.find('.', 1)); // Format the output
        std::clog << "\033[1;37mCounting Sort:\033[0m" << std::endl;
        std::clog << "\033[1;35m\tOutputing to: " << input + ".counting.out\033[0m" << std::endl;
        
        this->sort(data, data_size, order_function); // Sort the data
        
        std::clog << "\033[1;35m\tProcessing time: " << this->getElapsed() << " seconds\033[0m" << std::endl;

        this->file_handler_->writeToOutput(input + ".counting.out", data, data_size); // Write to the output file
        delete[] data; // Free the data
    }
};


#endif // define SORTING_ALGORITHMS_COUNTING_SORT_H
