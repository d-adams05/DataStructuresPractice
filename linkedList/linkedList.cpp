#include "LinkedList.h"
#include <string>
#include <iostream>

// Basic destructor
LinkedList::~LinkedList() {
	LinkedListNode* temp = head; // Start at the beginning of the list

	// Loops through list until the end
	while (temp != nullptr) {
		LinkedListNode* nextNode = temp->next; // Store the next node
		delete temp; // Delete the current node
		temp = nextNode; // Move to the next node
	}

	head = nullptr; // For safety
	tail = nullptr;
}

// Copy constructor
LinkedList::LinkedList(const LinkedList& oldList) {
	if (oldList.head == nullptr) { // If old list is empty
		head = nullptr; // Set null
		tail = nullptr;
		return; // No point in doing anything else
	}

	LinkedListNode* temp = oldList.head; // Start at the beginning of the old list

	// Loops through list until the end
	while (temp != nullptr) {
		append(temp->data); // Add old data to new list. Head/tail assignment handled by function
		temp = temp->next; // Move to the next node
	}
}

// Append new data to the end of the list
void LinkedList::append(const std::string& data) {
	LinkedListNode* temp = new LinkedListNode(data); // Create new node

	if (head == nullptr) { // If list empty, new node is the head and tail
		head = temp;
	} else {
		tail->next = temp; // Current tail's next is now new node
	}

	tail = temp; // New node is now the tail
}

// Prepend new data to the beginning of the list
void LinkedList::prepend(const std::string& data) {
	LinkedListNode* temp = new LinkedListNode(data); // Create new node

	if (head == nullptr) { // If list empty, new node is the head and tail
		tail = temp;
	} else {
		temp->next = head; // Current tail's next is now new node
	}

	head = temp; // New node is now the head
}

// Remove the node with the corresponding data
bool LinkedList::remove(const std::string& data) {
	if (head == nullptr) return false; // List is empty so nothing to remove
	
	LinkedListNode* temp = head;
	LinkedListNode* prev = nullptr;

	// Loop through the list
	while (temp != nullptr) {
		if (temp->data == data) { // If data matches this node's data
			// Case where node is the only one in the list
			if (temp == head && temp == tail) {
				head = nullptr; // List is empty now
				tail = nullptr;

			// Case where the node is the head node
			} else if (temp == head) {
				head = temp->next; // The new head is the next node in the list

			// Case where the node is the tail node
			} else if (temp == tail) { 
				tail = prev; // The new tail is the previous node
				tail->next = nullptr; // There is nothing after the tail now

			// Otherwise it is a node in the middle of the list
			} else { 
				prev->next = temp->next; // The previous node's next is the current node's next
			}

			delete temp; // Delete temp
			return true; // Return true because there was a removal
		}

		prev = temp;
		temp = temp->next;
	}

	return false; // If not found, return false for no removal
}

// Display the linked list to the console
void LinkedList::display(std::ostream& os) {
	LinkedListNode* temp = head; // Start at the beginning
	// Loop through the list
	while (temp != nullptr) {
		os << temp->data << " "; // Output the data to the ostream with a space
		temp = temp->next; // Move to the next node
	}
	os << std::endl; // End the line
}

// Operator overload to make outputting the list easier
std::ostream& operator<<(std::ostream& os, LinkedList& list) {
	list.display(os);
	return os;
}