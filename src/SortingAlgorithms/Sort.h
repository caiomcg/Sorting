/**
 * @file Sort.h
 *
 * @class Sort
 *
 * @brief Base class for the sorting algorithms
 *
 * Delegates how timers and the main sorting funtion are defined
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
#ifndef SORTING_ALGORITHMS_SORT_H
#define SORTING_ALGORITHMS_SORT_H

#include <functional> // Function Objects
#include <ctime>      // Clock status

#include "FileHandler.h"

template <typename T> // Defines the class as a template
class Sort { // Defines the class
private:
    std::clock_t start_time_; // Stores the time at the start of the call to sort
    std::clock_t final_time_; // Stores the time at the end of the call to sort       
protected:
    FileHandler<T>* file_handler_;
    /**
     * @brief Update the start_time_ variable
     */
    void startTimer() {
        start_time_ = std::clock(); // Get current time
    }
    /**
     * @brief Update the final_time_ variable
     */
    void stopTimer() {
        final_time_ = std::clock(); // Get current time
    }
    /**
     * @brief Swap two values
     * 
     * @param first Value to be swaped
     * @param second Value to be swaped
     */
    void swap(T& first, T& second) {
        T temp = first; // Store the first value in a temporary variable
        first = second; // Move the second value to the first variable
        second = temp;  // Move the data from the first variable to the second
    }    
public:
    /**
     * @brief Default constructor
     */
    Sort() {
        file_handler_ = new FileHandler<T>{};
    }
    /**
     * @brief Default destructor
     */
    virtual ~Sort() {
        if (this->file_handler_ != nullptr) {
            delete this->file_handler_;
            this->file_handler_ = nullptr;
        }
    }
    /**
     * @brief Declare the sorting function
     * @details Every sorting algorithm implement the sorting method and defines how it behaves
     * 
     * @param arr The array to be sorted
     * @param size The size of the array
     * @param order_function The function that defines how the ordering will be done
     */
    virtual void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) = 0;  
    /**
     * @brief Test the algorithm
     * 
     * @param input Input to be sorted
     * @param order_function The function that defines how the ordering will be done
     */
    virtual void test(std::string input, std::function<bool(T& first, T& last)> order_function) = 0;
    /**
     * @brief Returns the elapsed time based on the start and final time
     *
     * @return The elapsed time
     */
    double getElapsed() const {
        return (final_time_ - start_time_) / (double) CLOCKS_PER_SEC; // Return the elapsed time in seconds
    }
    

};

#endif // define SORTING_ALGORITHMS_SORT_H