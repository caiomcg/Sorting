/**
 * @file QuickSort.h
 *
 * @class QuickSort
 *
 * @brief Quick sort implementation
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

 #ifndef SORTING_ALGORITHMS_QUICK_SORT_H
 #define SORTING_ALGORITHMS_QUICK_SORT_H
 
 #include "Sort.h" // Sort base class
 
 template <typename T> // Defines the class as a template
 class QuickSort : public Sort<T> { // Defines the class
 public:
     /**
      * @brief Default constructor
      */
     QuickSort() {}
 
     /**
      * @brief Define how Insertion Sort behaves
      * 
      * @param arr The array to be sorted
      * @param size The size of the array
      * @param order_function The function that defines how the ordering will be done
      */
     void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
         this->startTimer(); // Stores the start time of the sorting
 
         for (int i = 1, j = 0; i < size; i++) { // Iterate through the array
             T current_value = arr[i]; // Store the base value to be compared
         
             for (j = i - 1; j >= 0 && order_function(arr[j], current_value); j--) { // Do a reverse search and based on the user decision sort the array
                 arr[j + 1] = arr[j]; // Shift the values
             }
 
             arr[j + 1] = current_value; // Add the base value
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
         int* data = nullptr; // Pointer to the data fetched from the input
         int data_size = this->file_handler_->fetchInput(input, &data); // Fetch from the input
         if (data_size == 0) { // If no data on the file we stop the process
             if (data != nullptr) delete data; // Free the data buffer
             std::clog << "\033[1;30mInvalid input. Terminating\033[0m" << std::endl;
             return; // Stop the test
         }
         
         input.erase(input.find('.', 1)); // Format the output
         std::clog << "\033[1;37mInsertion Sort:\033[0m" << std::endl;
         std::clog << "\033[1;35m\tOutputing to: " << input + ".insertion.out\033[0m" << std::endl;
         
         this->sort(data, data_size, order_function); // Sort the data
         
         std::clog << "\033[1;35m\tProcessing time: " << this->getElapsed() << " seconds\033[0m" << std::endl;
 
         this->file_handler_->writeToOutput(input + ".insertion.out", data, data_size); // Write to the output file
         delete data; // Free the data
     }
 };
 
 
 #endif // define SORTING_ALGORITHMS_QUICK_SORT_H
 