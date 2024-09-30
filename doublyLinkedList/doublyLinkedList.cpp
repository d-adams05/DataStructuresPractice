#include "doublyLinkedList.h"
#include <string>
#include <iostream>

// Basic destructor
DoublyLinkedList::~DoublyLinkedList() {
	DoublyLinkedListNode* temp = head; // Start at the beginning of the list

	// Loops through list until the end
	while (temp != nullptr) {
		DoublyLinkedListNode* nextNode = temp->next; // Store the next node
		delete temp; // Delete the current node
		temp = nextNode; // Move to the next node
	}

	head = nullptr; // For safety
	tail = nullptr;
}

// Copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& oldList) {
	if (oldList.head == nullptr) { // If old list is empty
		head = nullptr; // Set null
		tail = nullptr;
		return; // No point in doing anything else
	}

	DoublyLinkedListNode* temp = oldList.head; // Start at the beginning of the old list

	// Loops through list until the end
	while (temp != nullptr) {
		append(temp->data); // Add old data to new list. Head/tail assignment handled by function
		temp = temp->next; // Move to the next node
	}
}

// Append new data to the end of the list
void DoublyLinkedList::append(const std::string& data) {
	DoublyLinkedListNode* temp = new DoublyLinkedListNode(data); // Create new node

	if (head == nullptr) { // If list empty, new node is the head and tail
		head = temp;
	} else {
		tail->next = temp; // Current tail's next is now new node
		temp->prev = tail; // New node's previous is the old tail
	}

	tail = temp; // New node is now the tail
}

// Prepend new data to the beginning of the list
void DoublyLinkedList::prepend(const std::string& data) {
	DoublyLinkedListNode* temp = new DoublyLinkedListNode(data); // Create new node

	if (head == nullptr) { // If list empty, new node is the head and tail
		tail = temp;
	} else {
		temp->next = head; // Current tail's next is now new node
		head->prev = temp; // Head's previous node is now the new node
	}

	head = temp; // New node is now the head
}

// Remove the node with the corresponding data
bool DoublyLinkedList::remove(const std::string& data) {
	if (head == nullptr) return false; // List is empty so nothing to remove

	DoublyLinkedListNode* temp = head; // Start from the beginning

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
				head->prev = nullptr; // The new head will not have anything before it

				// Case where the node is the tail node
			} else if (temp == tail) {
				tail = temp->prev; // The new tail is the previous node
				tail->next = nullptr; // There is nothing after the tail now

				// Otherwise it is a node in the middle of the list
			} else {
				temp->prev->next = temp->next; // The node before temp should connect to the node after temp
				temp->next->prev = temp->prev; // The node after temp should conenct to the node before temp
			}

			delete temp; // Delete temp
			return true; // Return true because there was a removal
		}

		temp = temp->next; // Goes forwards
	}

	return false; // If not found, return false for no removal
}

// Display the linked list to the console
void DoublyLinkedList::display(std::ostream& os) {
	DoublyLinkedListNode* temp = head; // Start at the beginning
	// Loop through the list
	while (temp != nullptr) {
		os << temp->data << " "; // Output the data to the ostream with a space
		temp = temp->next; // Move to the next node
	}
	os << std::endl; // End the line
}

// Operator overload to make outputting the list easier
std::ostream& operator<<(std::ostream& os, DoublyLinkedList& list) {
	list.display(os);
	return os;
}

// Remove the node with the corresponding data, starting from the tail
bool DoublyLinkedList::tailRemove(const std::string& data) {
	if (head == nullptr) return false; // List is empty so nothing to remove

	DoublyLinkedListNode* temp = tail; // Start from the end

	// Loop through the list
	while (temp != nullptr) {
		if (temp->data == data) { // If data matches this node's data
			// Case where node is the only one in the list
			if (temp == head && temp == tail) {
				head = nullptr; // List is empty now
				tail = nullptr;

				// Case where the node is the head node
			}
			else if (temp == head) {
				head = temp->next; // The new head is the next node in the list
				head->prev = nullptr; // The new head will not have anything before it

				// Case where the node is the tail node
			}
			else if (temp == tail) {
				tail = temp->prev; // The new tail is the previous node
				tail->next = nullptr; // There is nothing after the tail now

				// Otherwise it is a node in the middle of the list
			}
			else {
				temp->prev->next = temp->next; // The node before temp should connect to the node after temp
				temp->next->prev = temp->prev; // The node after temp should conenct to the node before temp
			}

			delete temp; // Delete temp
			return true; // Return true because there was a removal
		}

		temp = temp->prev; // Goes backwards
	}

	return false; // If not found, return false for no removal
}

// Display the linked list to the console, starting from the tail
void DoublyLinkedList::tailDisplay(std::ostream& os) {
	DoublyLinkedListNode* temp = tail; // Start at the tail
	// Loop through the list
	while (temp != nullptr) {
		os << temp->data << " "; // Output the data to the ostream with a space
		temp = temp->prev; // Move to the prev node
	}
	os << std::endl; // End the line
}