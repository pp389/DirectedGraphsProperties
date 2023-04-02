#pragma once
#include <fstream>
#include <vector>
#include "List.h"

/**
* This class represents a directed graph. 
*/
class DirectedGraph {
private:
	std::vector<std::vector<int>> incidenceMatrix;
	std::fstream& inputFile;
	int numberOfVertices, numberOfEdges;
	List** incidenceList;

	/**
	* This function calculates how many vertices are in graph and saves this information to "numberOfVertices" variable.
	* @param inputFile - reference to an object from which we access the file which contains definition of the graph
	*/
	void calculateNumberOfVertices();

	void createIncidenceList();

	void loadDataFromFile();
public:
	DirectedGraph(std::fstream& fileWithGraphData) : inputFile(fileWithGraphData), numberOfVertices(0), numberOfEdges(0) { loadDataFromFile(); createIncidenceList(); };

	~DirectedGraph();
	
	/**
	* Saves the incidence matrix to two-dimensional array.
	* @return pointer to two-dimensional array which contains incidence matrix
	*/
	int** saveIncidenceMatrixToArray() const;

	std::vector<std::vector<int>> getIncidenceMatrix() const { return incidenceMatrix; }

	/**
	* This function views the incidence matrix which can be read from two-dimensional array.
	*/
	void viewIncidenceMatrix() const;

	/**
	* This function views all neighbours of each vertex
	*/
	void viewAllNeighboursOfEachVertex() const;

	/**
	* Returns number of vertices in graph.
	* @return integer value of "numberOfVertices"
	*/
	int getNumberOfVertices() const { return numberOfVertices; }

	/**
	* Returns number of edges in graph.
	* @return integer value of "numberOfEdges"
	*/
	int getNumberOfEdges() const { return numberOfEdges; }

	/**
	* Views the indegree value of each vertex.
	*/
	void viewIndegrees() const;

	/**
	* Views the outdegree value of each vertex.
	*/
	void viewOutdegrees() const;
};

