/**
 * @file HeapSort.h
 *
 * @class HeapSort
 *
 * @brief Heap sort implementation
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

#ifndef SORTING_ALGORITHMS_HEAP_SORT_H
#define SORTING_ALGORITHMS_HEAP_SORT_H

#include "Sort.h" // Sort base class

template <typename T> // Defines the class as a template
class HeapSort : public Sort<T> { // Defines the class
public:
    /**
    * @brief Default constructor
    */
    HeapSort() {}

    /**
     * @brief Keep the tree as a max heap
     * 
     * @param arr Array to be analysed
     * @param size The size of the array
     * @param index The root index
     */
    void MAX_HEAPIFY(T* arr, int size, int index) {
        int largest = index; // Store the largest element index(Root by default)
        int left    = (index << 1) + 1; // Calculate the location of the left child on the array
        int right   = (index << 1) + 2; // Calculate the location of the right child on the array

        if (left < size && arr[left] > arr[largest]) { // Check if the left side child is larger than the current largest and if
                                                       // we have not passed through the array bounds
            largest = left; // Store the new largest element index
        }
        if (right < size && arr[right] > arr[largest]) { // Check if the right side child is larger than the current largest and if
                                                         // we have not passed through the array bounds
            largest = right; // Store the new largest element index
        }
        if (largest != index) { // If the largest is not the root
            this->swap(arr[index], arr[largest]); // Swap the elements
            this->MAX_HEAPIFY(arr, size, largest); // Call MAX_HEAPIFY recursively for the current largest
        }
    }

    /**
     * @brief Create a max heap tree for an array
     * 
     * @param arr The array to be ordered
     * @param size The size of the array
     */
    void BUILD_MAX_HEAP(T* arr, int size) {
        for (int i = size / 2; i >= 0; i--) { // Iterate through the nodes of the heap
            this->MAX_HEAPIFY(arr, size, i); // Apply MAX HEAPIFY on every node
        }
    }

    /**
    * @brief Define how Heap Sort behaves
    * 
    * @param arr The array to be sorteds
    * @param size The size of the array
    * @param order_function The function that defines how the ordering will be done
    */
    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        this->startTimer(); // Stores the start time of the sorting

        this->BUILD_MAX_HEAP(arr, size); // Construct the heap tree

        for (int i = size - 1; i >= 0; i--) { // Iterate through the nodes
            this->swap(arr[0], arr[i]); // Order the elements as the root is sorted from biggest to smallest
            this->MAX_HEAPIFY(arr, i, 0); // Reorder at every element shift
        }

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
        std::clog << "\033[1;37mHeap Sort:\033[0m" << std::endl;
        std::clog << "\033[1;35m\tOutputing to: " << input + ".heap.out\033[0m" << std::endl;
        
        this->sort(data, data_size, order_function); // Sort the data
        
        std::clog << "\033[1;35m\tProcessing time: " << this->getElapsed() << " seconds\033[0m" << std::endl;

        this->file_handler_->writeToOutput(input + ".heap.out", data, data_size); // Write to the output file
        delete data; // Free the data
    }
};
 
 
#endif // define SORTING_ALGORITHMS_HEAP_SORT_H
 