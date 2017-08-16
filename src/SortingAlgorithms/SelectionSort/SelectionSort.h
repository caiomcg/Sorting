#pragma once

#include "Sort.h"

template <typename T>
class SelectionSort : public Sort<T> {
public:
    SelectionSort() {}

    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        this->startTimer();

        for (unsigned i = 0; i < size; i++) {
            unsigned current_location = i;
            for (unsigned j = i + 1; j < size; j++) {
                if (order_function(arr[current_location], arr[j])) {
                    current_location = j;
                }
            }
            this->swap(arr[current_location], arr[i]);
        }
        
        this->stopTimer();
    }

};