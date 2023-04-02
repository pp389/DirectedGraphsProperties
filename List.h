#pragma once

#include <iostream>

/**
* This class represents a singly linked list
*/
class List {

private:
	//this structure represents element of the list
	struct ListElement {
		ListElement* next; //pointer to the next element
		int value; //value stored in element
	};

	ListElement* head; //pointer to the head of the list
	ListElement* tail; //pointer to the tail of the list
	int numberOfElements;

	/**
	* Creates new ListElement instance with specified value and pointer to the next element 
	* @param next - pointer to the next element of list
	* @param value - value which will be stored in created element
	*/
	ListElement* createListElement(ListElement* next, int value);

public:
	/**
	* Constructs list with no elements
	*/
	List() { head = nullptr; tail = nullptr; numberOfElements = 0; };

	~List();

	/**
	* Constructs list with one element which stores specified value
	* @param firstValue - value to be stored in first element
	*/
	List(int firstValue) { List(); addElementToTheBeginning(firstValue); tail = head; };

	/**
	* Adds element to the beginning of the list
	* @param value - value to be stored in the new head of the list
	*/
	void addElementToTheBeginning(int value);

	/**
	* Adds element to the end of the list
	* @param value - value to be stored in the new tail of the list
	*/
	void addElementToTheEnd(int value);

	/**
	* Removes element which stores specified value
	* @param value - value which must stored by element to be removed
	*/
	void removeElement(int value);

	/**
	* Returns number of elements in list
	* @return number of elements in list
	*/
	int getNumberOfElements() const { return numberOfElements; };

	/**
	* Checks if list is empty
	* @return true if list is empty and false otherwise
	*/
	bool isEmpty() const { return getNumberOfElements() == 0 ? true : false; };

	/**
	* Views in the console all the elements of the list
	*/
	void viewAllElements() const;

	/**
	* Views in the console value stored in head of the list
	*/
	void viewValueInHead() const { std::cout << head->value << std::endl; };

	/**
	* Views in the console value stored in tail of the list
	*/
	void viewValueInTail() const { std::cout << tail->value << std::endl; };
};
