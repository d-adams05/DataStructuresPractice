#pragma once
#include <ostream>

#ifndef NODE_STACK
#define NODE_STACK
class StackNode {
	public:
		StackNode() : data(0), next(nullptr) {} // Default constructor
		StackNode(int data) : data(data), next(nullptr) {} // Construct given data

		int data; // Data to store, can be any data type
		StackNode* next; // Points to the next node in the stack, the one below this node
};
#endif

#ifndef STACK
#define STACK
class Stack {
	private:
		StackNode* top;

	public:
		Stack() : top(nullptr) {} // Default constructor
		~Stack(); // Default destructor

		void push(int data); // Puts a new node with the given data at the top of the stack
		bool pop(); // Removes the node at the top of the stack
		bool peek(int& data); // Sets the given variable to the data at the top of the stack
		void display(std::ostream& os); // Display the stack to the console
		friend std::ostream& operator<<(std::ostream& os, Stack& stack); // Makes displaying easier
};
#endif