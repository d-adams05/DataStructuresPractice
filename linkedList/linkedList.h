#pragma once
#include <string>

#ifndef NODE_SINGLE_LINKED_LIST
#define NODE_SINGLE_LINKED_LIST
class LinkedListNode {
	public:
		LinkedListNode() : data(""), next(nullptr) {} // Default constructor
		LinkedListNode(std::string data) : data(data), next(nullptr) {} // Construct given data

		std::string data; // Data to store, can be any data type
		LinkedListNode* next; // Points to the next node in the list
};
#endif

#ifndef LINKED_LIST
#define LINKED_LIST
class LinkedList {
	public:
		LinkedList() : head(nullptr), tail(nullptr) {} // Default constructor
		~LinkedList(); // Default destructor
		LinkedList(const LinkedList& oldList); // Constructor that copies another list

		LinkedListNode* head; // The start of the list
		LinkedListNode* tail; // The end of the list

		void append(const std::string& data); // Add a node to the end of the list
		void prepend(const std::string& data); // Add a node to the beginning of the lsit
		bool remove(const std::string& data); // Remove the node with the corresponding data
		void display(std::ostream& os); // Output the list
		friend std::ostream& operator<<(std::ostream& os, LinkedList& list); // Makes outputting the list easier
};
#endif