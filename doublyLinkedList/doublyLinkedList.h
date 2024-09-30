#pragma once
#include <string>

#ifndef NODE_DOUBLY_LINKED_LIST
#define NODE_DOUBLY_LINKED_LIST
class DoublyLinkedListNode {
	public:
		DoublyLinkedListNode() : data(""), next(nullptr), prev(nullptr) {} // Default constructor
		DoublyLinkedListNode(std::string data) : data(data), next(nullptr), prev(nullptr) {} // Construct given data

		std::string data; // Data to store, can be any data type
		DoublyLinkedListNode* next; // Points to the next node in the list
		DoublyLinkedListNode* prev; // Points to the previous node in the list
};
#endif

#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
class DoublyLinkedList {
	public:
		DoublyLinkedList() : head(nullptr), tail(nullptr) {} // Default constructor
		~DoublyLinkedList(); // Default destructor
		DoublyLinkedList(const DoublyLinkedList& oldList); // Constructor that copies another list

		DoublyLinkedListNode* head; // The start of the list
		DoublyLinkedListNode* tail; // The end of the list

		void append(const std::string& data); // Add a node to the end of the list
		void prepend(const std::string& data); // Add a node to the beginning of the lsit
		bool remove(const std::string& data); // Remove the node with the corresponding data
		void display(std::ostream& os); // Output the list
		friend std::ostream& operator<<(std::ostream& os, DoublyLinkedList& list); // Makes outputting the list easier

		bool tailRemove(const std::string& data); // Remove the node with the corresponding data, starting from the end of the list
		void tailDisplay(std::ostream& os); // Output the list backwards; starts at the end
};
#endif