#include "Stack.h"
#include <string>

Stack::Stack() { 
	setName(name, desc); 

	menu.addChoice("1", "Push", "", 1);
	menu.addChoice("2", "Pop");
	menu.addChoice("3", "IsEmpty");
	menu.addChoice("4", "Print");
	menu.addChoice("5", "Clear", "Reset all data");
}

void Stack::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		cout << "Result: " << endl;
		switch (idInt) {
			case 1:
				push(params[0]);
				break;
			case 2:
				pop();
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

void Stack::push(int el) {
	if (top >= (MAX_ELEMENTS - 1)) {
		cout << "Error, stack overflow" << endl;
	}
	else {
		stack[++top] = el;
		cout << "Success" << endl;
	}
}

void Stack::pop() {
	if (top < 0) {
		cout << "Stack is empty" << endl;
	}
	else {
		cout << "Popped:  " << stack[top--] << endl;
	}
}

void Stack::isEmpty() {
	if (top < 0)
		cout << "Stack is empty" << endl;
	else
		cout << "Stack is NOT empty" << endl;
}

void Stack::print() {
	for (int i = top; i >= 0; i--)
		cout << stack[i] << endl;

	cout << endl;
}

void Stack::clear() {
	top = -1;

	cout << "Stacked has been cleaned" << endl;
}