#pragma once
#include <ostream>

#ifndef NODE_QUEUE
#define NODE_QUEUE
class QueueNode {
	public:
		QueueNode() : data(0), next(nullptr) {} // Default constructor
		QueueNode(int data) : data(data), next(nullptr) {} // Construct given data

		int data; // Data to store, can be any data type
		QueueNode* next; // Points to the next node in the queue, the one next in line
};
#endif

#ifndef QUEUE
#define QUEUE
class Queue {
	private:
		QueueNode* first; // First node in the queue
		QueueNode* last; // Last node in the queue

	public:
		Queue() : first(nullptr), last(nullptr) {} // Default constructor
		~Queue(); // Default destructor

		void push(int data); // Puts a new node with the given data at the end of the queue
		bool pop(); // Removes the node at the front of the queue
		bool peek(int& data); // Sets the given variable to the data at the front of the queue
		void display(std::ostream& os); // Display the queue to the console
		friend std::ostream& operator<<(std::ostream& os, Queue& queue); // Makes displaying easier
};
#endif