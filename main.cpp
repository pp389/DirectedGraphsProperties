#include <iostream>
#include "LibFiles.h"
#include "DirectedGraph.h"

int main() {
	std::string fileName;
	std::fstream inputFile;

	std::cout << "Name of input file: ";
	std::cin >> fileName;
	openFile(inputFile, fileName);

	DirectedGraph graph(inputFile);
	std::cout << "Incidence matrix:" << std::endl;
	graph.viewIncidenceMatrix();
	std::cout << "Neighbours of each vertex:" << std::endl;
	graph.viewAllNeighboursOfEachVertex();
	std::cout << "Indegrees:" << std::endl;
	graph.viewIndegrees();
	std::cout << "Outdegrees:" << std::endl;
	graph.viewOutdegrees();

	return 0;
}