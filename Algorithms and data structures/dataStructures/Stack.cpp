#include "Stack.h"
#include <string>

Stack::Stack() { 
	setName(name, desc); 

	menu.addChoice("1", "Push", "O(1)", 1);
	menu.addChoice("2", "Pop", "O(1)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void Stack::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
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
		menu.addResult("Error, stack overflow");
	}
	else {
		stack[++top] = el;
		menu.addResult("Success");
	}
}

void Stack::pop() {
	if (top < 0) {
		menu.addResult("Stack is empty");
	}

	else {
		menu.addResult("Popped:  " + to_string(stack[top--]));
	}
}

void Stack::isEmpty() {
	if (top < 0)
		menu.addResult("Stack is empty");
	else
		menu.addResult("Stack is NOT empty");
}

void Stack::print() {
	for (int i = top; i >= 0; i--)
		menu.addResult(to_string(stack[i]));

}

void Stack::clear() {
	top = -1;

	menu.addResult("Stacked has been cleaned");
}