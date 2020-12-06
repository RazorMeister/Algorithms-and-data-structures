#include "UnorderedList.h"
#include <string>

UnorderedList::UnorderedList() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(1)", 1);
	menu.addChoice("2", "Max", "O(n)");
	menu.addChoice("3", "DeleteMax", "O(n)");
	menu.addChoice("4", "IsEmpty", "O(1)");
	menu.addChoice("5", "Print", "O(n)");
	menu.addChoice("6", "Clear", "Reset all data");
}

void UnorderedList::callback(string id, vector<int> params) {
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

void UnorderedList::insert(int el) {
	if (!head) {
		head = new node{ el, nullptr };
	}
	else {
		node* newHead = new node{ el, head };
		head = newHead;
	}

	menu.addResult("Success");
}

void UnorderedList::max() {
	if (head) {
		node* n = head;
		int max = n->value;
		n = n->next;

		while (n) {
			if (n->value > max)
				max = n->value;

			n = n->next;
		}

		menu.addResult(to_string(max));
	}
	else {
		menu.addResult("UnorderedList is empty!");
	}
}

void UnorderedList::deleteMax() {
	if (head) {
		node* n = head;


		if (!head->next) {
			menu.addResult("Deleted: " + to_string(head->value));
			delete head;
			head = nullptr;
		}
		else {
			node* prevMax = head;
			node* max = head->next;
			node* n = head->next;

			while (n->next) {
				if (n->next->value > max->value) {
					prevMax = n;
					max = n->next;
				}

				n = n->next;
			}

			if (head->value > max->value) {
				menu.addResult("Deleted: " + to_string(head->value));
				node* n = head;
				head = head->next;
				delete n;
			}
			else {
				menu.addResult("Deleted: " + to_string(max->value));
				prevMax->next = max->next;
			}
		}
	}
	else {
		menu.addResult("UnorderedList is empty!");
	}
}

void UnorderedList::isEmpty() {
	if (!head)
		menu.addResult("UnorderedList is empty");
	else
		menu.addResult("UnorderedList is NOT empty");
}

void UnorderedList::print() {
	node* n = head;
	string result = "";

	while (n) {
		result += to_string(n->value) + ' ';
		n = n->next;
	}
		
	menu.addResult(result);
}

void UnorderedList::clear() {
	node* n = head;

	while (n) {
		node* old = n;
		n = n->next;
		delete old;
	}

	head = nullptr;

	menu.addResult("UnorderedList has been cleaned");
}