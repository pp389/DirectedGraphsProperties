#include "List.h"
#include <iostream>

List::ListElement* List::createListElement(List::ListElement* next, int value) {
	List::ListElement* newElement = new List::ListElement;
	newElement->next = next;
	newElement->value = value;
	return newElement;
}

void List::addElementToTheBeginning(int value) {
	List::ListElement* newElement = createListElement(head, value); //create new element which "next" pointer is set to the head of the list
	head = newElement; //created element is new head of the list
	numberOfElements++;

	if (tail == nullptr)
		tail = head;
}

void List::addElementToTheEnd(int value) {
	List::ListElement* newElement = createListElement(nullptr, value);

	if (head == nullptr) //if list is empty we must set also "head" pointer
		head = tail = newElement;
	else {
		tail->next = newElement;
		tail = newElement; //created element is the new tail of the list
	}

	numberOfElements++;
}

void List::removeElement(int value) {
	//check if head of the list is element which we want to remove
	if (head->value == value) { 
		List::ListElement* nextToHead = head->next;
		delete head;
		head = nextToHead;
		numberOfElements--;
		return;
	}

	List::ListElement* temp = head;
	//iterate through the list and search for the element to be removed
	while (temp->next != nullptr) { 
		if (temp->next->value == value) {
			//pointer to the element which will be removed
			List::ListElement* toBeRemoved = temp->next; 
			temp->next = toBeRemoved->next;
			delete toBeRemoved;
			numberOfElements--;
			break;
		}
		temp = temp->next;
	}
}

void List::viewAllElements() const {
	List::ListElement* temp = head;
	//iterate through the list and view all values stored in its elements
	while (temp != nullptr) { 
		std::cout << temp->value << " ";
		temp = temp->next;
	}
	std::cout << std::endl;
}

List::~List() {
	List::ListElement* element = head;
	while (element != nullptr) {
		List::ListElement* temp = element;
		element = element->next;
		delete temp;
	}
}