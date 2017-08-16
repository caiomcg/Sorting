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