#include "stack.h"

// Default destructor
Stack::~Stack() {
	StackNode* temp = top; // Start at the top of the stack

	// Loop through the stack, starts from the top
	while (temp != nullptr) {
		top = top->next; // Move the top to the next node
		delete temp; // Delete the old top
		temp = top; // Also move to the new top
	}

	top = nullptr; // For safety
}

// Puts a new node with the given data at the top of the stack
void Stack::push(int data) {
	StackNode* temp = new StackNode(data); // Create a new node and set the data
	temp->next = top; // Temp's next is the current top
	top = temp; // Temp is now the new top
}

// Removes the node at the top of the stack
bool Stack::pop() {
	if (top == nullptr) return false; // If the stack is empty, return failure
	StackNode* temp = top; // Get the top of the stack
	top = top->next; // Move the top to the next node
	delete temp; // Delete the old top
	return true; // Return success
}

// Sets the given variable to the data at the top of the stack
bool Stack::peek(int& data) {
	if (top == nullptr) return false; // If the stack is empty, return failure
	data = top->data; // Set the given variable to the data
	return true; // Return true because there was data to set
}

// Display the stack to the console
void Stack::display(std::ostream& os) {
	StackNode* temp = top; // Start at the top
	// Loop through the stack
	while (temp != nullptr) {
		// Output the data then a blank if end of the stack, otherwise an arrow
		os << temp->data << ((temp->next == nullptr) ? " " : " -> ");
		temp = temp->next; // Move to the next node
	}
	os << std::endl; // End the line
}

// Operator overload to make outputting the stack easier
std::ostream& operator<<(std::ostream& os, Stack& stack) {
	stack.display(os);
	return os;
}