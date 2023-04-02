#pragma once
#include <vector>

/**
* Allocates memory for two-dimensional array
* @param rows number of rows
* @param columns number of columns
* @return pointer to an array
*/
int** createTwoDimensionalArray(int rows, int columns);

/**
* Saves data from std::vector container filled with other std::vector containers. 
* @param vector - reference to std::vector which contains data to copy.
* @return pointer to two-dimensional array filled with data from std::vector.
*/
int** saveDataFromVectorToArray(std::vector<std::vector<int>> vector);