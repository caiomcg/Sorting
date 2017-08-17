/**
 * @file FileHandler.h
 *
 * @class FileHandler
 *
 * @brief Handle file I/O
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

#ifndef  UTILS_FILE_HANDLER_H
#define  UTILS_FILE_HANDLER_H

#include <fstream> // File manipulation
#include <vector>  // STL Vector
#include <string>  // C++ string
#include <cstring> // C string

template<typename T>
class FileHandler {
public:
    /**
     * @brief Default constructor
     */
    FileHandler() {}
    /**
     * @brief Default destructor
     */
    ~FileHandler() {}
    /**
     * @brief Fetch data from a file and store in an array
     * 
     * @param input_name File to fetch the input
     * @param data Pointer where the data will be stored
     * 
     * @return The size of data
     */
    int fetchInput(std::string input_name, T** data) {
        std::vector<T> elements; // Holds the elements temporarily
        T temp; // Elements fetched from the input are first placed in here

        std::fstream input(input_name, std::ios::in); // Open the input file
        if (input.is_open()) { // Check if it is open
            while(input >> temp) { // Fetch until EOF
                elements.push_back(temp); // Add to the vector
            }
        }
        input.close(); // Close the file

        *data = new T[elements.size()]; // Alloc the pointer
        memcpy(*data, elements.data(), elements.size() * sizeof(T)); // Copy the data from the vector to the data pointer

        return elements.size(); // Return the size of the vector
    }
    /**
     * @brief Write to an output file
     * 
     * @param output_name The ouput file name
     * @param data Data to write at the file
     * @param size The size of data
     */
    void writeToOutput(const std::string& output_name, T* data, int size) {
        std::fstream output(output_name, std::ios::out); // Open the output file
        if (output.is_open()) { // Check if it is open
            for (int i = 0; i < size; i++) { // Iterate through the data
                output << data[i] << "\n"; // Add the data to the file
            }
        }
        output.close(); // Close the file
    }

};

#endif // define UTILS_FILE_HANDLER_H