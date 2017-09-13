/**
 * @file RadixSort.h
 *
 * @class RadixSort
 *
 * @brief Radix sort implementation
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

#ifndef SORTING_ALGORITHMS_RADIX_SORT_H
#define SORTING_ALGORITHMS_RADIX_SORT_H

#include "Sort.h" // Sort base class

template <typename T> // Defines the class as a template
class RadixSort : public Sort<T> { // Defines the class
public:
    /**
    * @brief Default constructor
    */
    RadixSort() {}

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

    void radixSort(T* arr, const unsigned& size, T max_num) {
        int position = 1; // through the least significant digit

        T* counterArray = nullptr; // Array with element counting(by significant digit)
        T* sorted = new T[size](); // Sorted Array
        

        while (max_num / position > 0) { // While we have not reached the most significant digit
            counterArray = new T[10](); // Initialize the array zeroed

            for (int i = 0; i < size; i++) {
                counterArray[(arr[i] / position) % 10] += 1; // For each significant element, increment the position with the digit
            }

            for (int i = 1; i < 10; i++) {
                counterArray[i] += counterArray[i - 1]; // Add next to previous sum
            }

            for (int i = size - 1; i >= 0; i--){
                counterArray[(arr[i] / position) % 10] -= 1; // Decrement the position
                sorted[counterArray[(arr[i] / position) % 10]] = arr[i]; // Assigned the element to its new position
            }

            for (int i = 0; i < size; i++) {
                arr[i] = sorted[i]; // Copy to the original array
            }
            
            position *= 10; // Pick a new digit
            delete counterArray; // Delete the counter array
        }
 
        delete sorted; // Delete the sorted array
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

        this->radixSort(arr, size, max);

        this->stopTimer(); // Stores the time at the end of the sorting
    }

    /**
    * @brief Test the algorithm
    * 
    * @param input Input to be sorted
    * @param order_function The function that defines how the ordering will be done
    */
    void test(std::string input, std::function<bool(T& first, T& last)> order_function) {
        int* data = nullptr; // Pointer to the data fetched from the input
        int data_size = this->file_handler_->fetchInput(input, &data); // Fetch from the input
        
        if (data_size == 0) { // If no data on the file we stop the process
            if (data != nullptr) delete data; // Free the data buffer
            std::clog << "\033[1;30mInvalid input. Terminating\033[0m" << std::endl;
            return; // Stop the test
        }
        
        input.erase(input.find('.', 1)); // Format the output
        std::clog << "\033[1;37mRadix Sort:\033[0m" << std::endl;
        std::clog << "\033[1;35m\tOutputing to: " << input + ".radix.out\033[0m" << std::endl;
        
        this->sort(data, data_size, order_function); // Sort the data
        
        std::clog << "\033[1;35m\tProcessing time: " << this->getElapsed() << " seconds\033[0m" << std::endl;

        this->file_handler_->writeToOutput(input + ".radix.out", data, data_size); // Write to the output file
        delete data; // Free the data
    }
};

#endif // define SORTING_ALGORITHMS_RADIX_SORT_H
