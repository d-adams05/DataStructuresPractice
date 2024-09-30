#include "stack/stack.h"
#include "queue/queue.h"
#include "linkedList/linkedList.h"
#include "doublyLinkedList/doublyLinkedList.h"
#include <iostream>

using std::cout;
using std::endl;

void example_Stack();
void example_Queue();
void example_LinkedList();
void example_DoublyLinkedList();

/*
Generally, compare Stacks to Queues and Linked Lists to Doubly Linked Lists
Uncomment an example, view the function and the output, and look at the .cpp and .h file for the structure
*/

int main() {

	//example_LinkedList();
	//example_DoublyLinkedList();
	//example_Stack();
	//example_Queue();

	return 0;
}

void example_Stack() {
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);
	s.display(cout); // shoud output "5 -> 4 -> 3 -> 2 -> 1"

	s.pop();
	s.display(cout); // shoud output "4 -> 3 -> 2 -> 1"

	s.pop();
	s.pop();
	s.push(505);
	s.display(cout); // should output "505 -> 2 -> 1"

	int val = 0;
	s.peek(val);
	cout << "Val: " << val << endl; // should output 505
}

void example_Queue() {
	Queue q;

	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	q.push(5);
	q.display(cout); // shoud output "1 <- 2 <- 3 <- 4 <- 5"

	q.pop();
	q.display(cout); // shoud output "2 <- 3 <- 4 <- 5"

	q.pop();
	q.pop();
	q.push(505);
	q.display(cout); // should output "4 <- 5 <- 505"

	int val = 0;
	q.peek(val);
	cout << "Val: " << val << endl; // should output 4
}

void example_LinkedList() {
	LinkedList LL;

	LL.append("structures");
	LL.append("can");
	LL.append("efficiently");
	LL.append("manage");
	LL.append("large");
	LL.append("amounts");
	LL.append("of");
	LL.append("data");
	LL.display(cout); // should output "structures can efficientlly manage large amounts of data"

	LL.remove("can");
	LL.display(cout); // should output "structures efficientlly manage large amounts of data"

	LL.prepend("data");
	LL.display(cout); // should output "data structures efficientlly manage large amounts of data"

	LL.remove("systems"); // doesn't do anything since systems is not in the list
	LL.display(cout); // should output "data structures efficientlly manage large amounts of data"
}

void example_DoublyLinkedList() {
	DoublyLinkedList DLL;

	DLL.append("structures");
	DLL.append("can");
	DLL.append("efficiently");
	DLL.append("manage");
	DLL.append("large");
	DLL.append("amounts");
	DLL.append("of");
	DLL.append("data");
	DLL.display(cout); // should output "structures can efficientlly manage large amounts of data"

	DLL.remove("can");
	DLL.display(cout); // should output "structures efficientlly manage large amounts of data"

	DLL.prepend("data");
	DLL.display(cout); // should output "data structures efficientlly manage large amounts of data"

	DLL.remove("systems"); // doesn't do anything since systems is not in the list
	DLL.display(cout); // should output "data structures efficientlly manage large amounts of data"

	DLL.tailDisplay(cout); // should output "data of amounts large manage efficiently structures data"

	DLL.tailRemove("data"); // will remove the data at the end of the list
	DLL.display(cout); // should output "data structures efficiently manage large amounts of "

	DLL.tailRemove("manage");
	DLL.display(cout); // should output "data structures efficiently large amounts of"
}