#include "OrderedList.h"
#include <string>

OrderedList::OrderedList() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(n)", 1);
	menu.addChoice("2", "Max", "O(1)");
	menu.addChoice("3", "DeleteMax", "O(1)");
	menu.addChoice("4", "IsEmpty", "O(1)");
	menu.addChoice("5", "Print", "O(n)");
	menu.addChoice("6", "Clear", "Reset all data");
}

void OrderedList::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
		case 1:
			insert(params[0]);
			break;
		case 2:
			max();
			break;
		case 3:
			deleteMax();
			break;
		case 4:
			isEmpty();
			break;
		case 5:
			print();
			break;
		case 6:
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

void OrderedList::insert(int el) {
	if (!head) {
		head = new node{ el, nullptr };
	} else if (el >= head->value) {
		head = new node{ el, head };
	}
	else {
		node* n = head;

		while (n->next && n->next->value > el) {
			n = n->next;
		}

		n->next = new node{ el, n->next };
	}

	menu.addResult("Success");
}

void OrderedList::max() {
	if (head) {
		menu.addResult(to_string(head->value));
	}
	else {
		menu.addResult("OrderedList is empty");
	}
}

void OrderedList::deleteMax() {
	if (head) {
		node* n = head;
		menu.addResult("Deleted: " + to_string(head->value));
		head = head->next;
		delete n;
	}
	else {
		menu.addResult("OrderedList is empty");
	}
}

void OrderedList::isEmpty() {
	if (!head)
		menu.addResult("OrderedList is empty");
	else
		menu.addResult("OrderedList is NOT empty");
}

void OrderedList::print() {
	node* n = head;
	string result = "";

	while (n) {
		result += to_string(n->value) + ' ';
		n = n->next;
	}
		
	menu.addResult(result);
}

void OrderedList::clear() {
	node* n = head;

	while (n) {
		node* old = n;
		n = n->next;
		delete old;
	}

	head = nullptr;

	menu.addResult("OrderedList has been cleaned");
}