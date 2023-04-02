#include "DirectedGraph.h"
#include "LibArrays.h"
#include <iostream>

void DirectedGraph::calculateNumberOfVertices() {
	inputFile >> numberOfEdges;
	//maximum number of vertex will specify size of one of the dimensions in two-dimensional array
	int vertex;
	while (inputFile >> vertex) {
		if (vertex > numberOfVertices)
			numberOfVertices = vertex;
	}

	//return to the beginning of file
	inputFile.clear();
	inputFile.seekg(0);
}

void DirectedGraph::createIncidenceList() {
	incidenceList = new List*[incidenceMatrix.size()];

	for (int i = 0; i < incidenceMatrix.size(); i++) {
		incidenceList[i] = new List();
	}

	//search neighbours for each vertex
	for (int i = 0; i < numberOfVertices; i++) {
		//iterate through edges
		for (int j = 0; j < numberOfEdges; j++) {
			//check if edge has begginning from current vertex
			if (incidenceMatrix[i][j] == 1) {
				//search for the end of the edge
				for (int k = 0; k < i; k++) {
					if (incidenceMatrix[k][j] == -1)
						incidenceList[i]->addElementToTheEnd(k + 1);
				}
				for (int k = i; k < numberOfVertices; k++) {
					if (incidenceMatrix[k][j] == -1)
						incidenceList[i]->addElementToTheEnd(k + 1);
				}
			}
		}
	}
}

void DirectedGraph::loadDataFromFile() {
	calculateNumberOfVertices();
	inputFile >> numberOfEdges;
	incidenceMatrix = std::vector<std::vector<int>>(numberOfVertices, std::vector<int>(numberOfEdges));

	for (int edge = 0; edge < numberOfEdges; edge++) {
		//read pair of numbers of vertices which define current edge
		int firstVertex, secondVertex;
		inputFile >> firstVertex >> secondVertex;

		incidenceMatrix[firstVertex - 1][edge] = 1;
		incidenceMatrix[secondVertex - 1][edge] = -1;
	}
}

int** DirectedGraph::saveIncidenceMatrixToArray() const {
	int** array = createTwoDimensionalArray(incidenceMatrix.size(), incidenceMatrix[0].size());
	
	for (int i = 0; i < incidenceMatrix.size(); i++) {
		for (int j = 0; j < incidenceMatrix[i].size(); j++)
			array[i][j] = incidenceMatrix[i][j];
	}

	return array;
}

void DirectedGraph::viewIncidenceMatrix() const {
	for (int i = 0; i < incidenceMatrix.size(); i++) {
		for (int j = 0; j < incidenceMatrix[i].size(); j++)
			std::cout << incidenceMatrix[i][j] << " ";

		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void DirectedGraph::viewAllNeighboursOfEachVertex() const {
	for (int i = 0; i < numberOfVertices; i++) {
		std::cout << i + 1 << ": ";
		incidenceList[i]->viewAllElements();
	}
}

void DirectedGraph::viewIndegrees() const {
	for (int i = 0; i < incidenceMatrix.size(); i++) {
		std::cout << i + 1 << ": ";
		int indegree = 0;
		for (int j = 0; j < incidenceMatrix[i].size(); j++)
			if (incidenceMatrix[i][j] == -1)
				indegree++;
		std::cout << indegree << std::endl;
	}
}

void DirectedGraph::viewOutdegrees() const {
	for (int i = 0; i < incidenceMatrix.size(); i++)
		std::cout << i + 1 << ": " << incidenceList[i]->getNumberOfElements() << std::endl;
}

DirectedGraph::~DirectedGraph() {
	inputFile.close();
	for (int i = 0; i < incidenceMatrix.size(); i++)
		delete incidenceList[i];
	delete[] incidenceList;
}