#include "queue.h"

// Default destructor
Queue::~Queue() {
	QueueNode* temp = first; // Start at the front of the queue

	// Loop through the queue, starts from the beginning
	while (temp != nullptr) {
		first = first->next; // Move the top to the next node
		delete temp; // Delete the old top
		temp = first; // Also move to the new top
	}

	first = nullptr; // For safety
	last = nullptr;
}

// Puts a new node with the given data at the end of the queue
void Queue::push(int data) {
	QueueNode* temp = new QueueNode(data); // Create a new node and set the data
	
	if (first == nullptr) { // If the queue is empty
		first = temp; // The new node is the first node
	} else { // Otherwise
		last->next = temp; // The new node goes after the last node
	}

	last = temp; // The new node is now the last node
}

// Removes the node at the beginnning of the queue
bool Queue::pop() {
	if (first == nullptr) return false; // If the queue is empty, return failure
	QueueNode* temp = first; // Get the front of the queue
	first = first->next; // Set the front of the queue to the next node
	if (first == nullptr) last = nullptr; // If there isn't a next node in the queue, the queue is now empty
	delete temp; // Delete the old front
	return true; // Return success
}

// Sets the given variable to the data at the front of the queue
bool Queue::peek(int& data) {
	if (first == nullptr) return false; // If the queue is empty, return failure
	data = first->data; // Set the given variable to the data
	return true; // Return true because there was data to set
}

// Display the queue to the console
void Queue::display(std::ostream& os) {
	QueueNode* temp = first; // Start at the top
	// Loop through the queue
	while (temp != nullptr) {
		// Output the data then a blank if end of the queue, otherwise an arrow
		os << temp->data << ((temp->next == nullptr) ? " " : " <- ");
		temp = temp->next; // Move to the next node
	}
	os << std::endl; // End the line
}

// Operator overload to make outputting the queue easier
std::ostream& operator<<(std::ostream& os, Queue& queue) {
	queue.display(os);
	return os;
}