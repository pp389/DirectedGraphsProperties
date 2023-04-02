#include "LibArrays.h"
#include <exception>
#include <iostream>

int** createTwoDimensionalArray(int rows, int columns) {
	int** array = nullptr;
	try {
		array = new int* [rows];
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		for (int i = 0; i < rows; i++)
			array[i] = new int[columns];

		for (int i = 0; i < rows; i++)
			for (int j = 0; j < columns; j++)
				array[i][j] = 0;
	}
	catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	return array;
}

int** saveDataFromVectorToArray(std::vector<std::vector<int>> vector) {
	int** array = createTwoDimensionalArray(vector.size(), vector[0].size());

	for (int i = 0; i < vector.size(); i++) {
		for (int j = 0; j < vector[i].size(); j++)
			array[i][j] = vector[i][j];
	}

	return array;
}