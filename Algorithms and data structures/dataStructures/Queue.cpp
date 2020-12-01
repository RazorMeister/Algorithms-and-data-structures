#include "Queue.h"
#include <string>

Queue::Queue() { 
	setName(name, desc); 

	menu.addChoice("1", "Put", "", 1);
	menu.addChoice("2", "Get");
	menu.addChoice("3", "IsEmpty");
	menu.addChoice("4", "Print");
	menu.addChoice("5", "Clear", "Reset all data");
}

void Queue::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
			case 1:
				put(params[0]);
				break;
			case 2:
				get();
				break;
			case 3:
				isEmpty();
				break;
			case 4:
				print();
				break;
			case 5:
				clear();
				break;
			default:
				break;
		}

		cout << endl;
	}
	catch (...) {
	}
}

void Queue::put(int el) {
	if (!head) {
		head = new node{ el, nullptr };
	}
	else {
		node* newHead = new node{ el, head };
		head = newHead;
	}

	menu.addResult("Success");
}

void Queue::get() {
	node* n = head;

	if (n) {
		// Only one element
		if (!n->next) {
			menu.addResult("Get: " + to_string(n->value));
			delete n;
			head = nullptr;
		}
		// Two or more elements
		else {
			while (n->next->next) {
				n = n->next;
			}

			menu.addResult("Get: " + to_string(n->next->value));
			delete n->next;
			n->next = nullptr;
		}
	}
	else {
		menu.addResult("Queue is empty");
	}
}

void Queue::isEmpty() {
	if (!head)
		menu.addResult("Queue is empty");
	else
		menu.addResult("Queue is NOT empty");
}

void Queue::print() {
	node* n = head;
	string result = "";

	while (n) {
		result += to_string(n->value) + ' ';
		n = n->next;
	}
		
	menu.addResult(result);
}

void Queue::clear() {
	node* n = head;

	while (n) {
		node* old = n;
		n = n->next;
		delete old;
	}

	head = nullptr;

	menu.addResult("Queue has been cleaned");
}