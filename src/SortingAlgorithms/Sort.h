#pragma once

#include <functional>

#include <ctime>

template <typename T>
class Sort {
private:
    std::clock_t start_time;
    std::clock_t final_time;       
protected:
    void startTimer() {
        start_time = std::clock();
    }

    void stopTimer() {
        final_time = std::clock();
    }

    void swap(T& first, T& second) {
        T temp = first;
        first = second;
        second = temp;
    }    
public:
    Sort() {}
    ~Sort() {}

    virtual void sort(T* arr, const unsigned& size, std::function<bool(T& first, T& last)> order_function) = 0; 

    double getElapsed() const {
        return (final_time - start_time) / (double) CLOCKS_PER_SEC;
    }
};
