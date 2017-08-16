#ifndef SORTING_ALGORITHMS_INSERTION_SORT_H
#define SORTING_ALGORITHMS_INSERTION_SORT_H

#include "Sort.h"

template <typename T>
class InsertionSort : public Sort<T> {
public:
    InsertionSort() {}

    void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) override {
        this->startTimer();

        for (int i = 1, j = 0; i < size; i++) {
            T current_value = arr[i];
        
            for (j = i - 1; j >= 0 && order_function(arr[j], current_value); j--) {
                arr[j + 1] = arr[j]; // Deslocamos os valores para o sentido passado pela função de ordenação
            }

            arr[j + 1] = current_value;
        }

        this->stopTimer();
    }
};


#endif // define SORTING_ALGORITHMS_INSERTION_SORT_H
