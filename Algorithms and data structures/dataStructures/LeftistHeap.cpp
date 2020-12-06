#include "LeftistHeap.h"
#include <string>

LeftistHeap::LeftistHeap() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(log n)", 1);
	menu.addChoice("2", "DeleteMax", "O(log n)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void LeftistHeap::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
			case 1:
				insert(params[0]);
				break;
			case 2:
				deleteMax();
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

LeftistHeap::node* LeftistHeap::hUnion(LeftistHeap::node *p1, LeftistHeap::node *p2) {
	node* p;

	if (!p1)
		return p2;
	if (!p2)
		return p1;

	if (p1->key > p2->key) {
		p = p1;
		p->right = hUnion(p1->right, p2);
	}
	else {
		p = p2;
		p2->right = hUnion(p2->right, p1);
	}

	if (!p->left || p->left->npl < p->right->npl) {
		node* q = p->left;
		p->left = p->right;
		p->right = q;
	}

	if (!p->right)
		p->npl = 0;
	else
		p->npl = p->right->npl + 1;

	return p;
}

void LeftistHeap::insert(int el) {
	node* p = new node;
	p->key = el;
	p->left = p->right = nullptr;
	p->npl = 0;

	root = hUnion(root, p);

	menu.addResult("Success");
}

void LeftistHeap::deleteMax() {
	if (!root) {
		menu.addResult("LeftistHeap is empty");
	}
	else {
		menu.addResult("Deleted: " + to_string(root->key));
		root = hUnion(root->left, root->right);
	}
}

void LeftistHeap::isEmpty() {
	if (!root)
		menu.addResult("LeftistHeap is empty");
	else
		menu.addResult("LeftistHeap is NOT empty");
}

void LeftistHeap::printRec(string &result, string prefix, LeftistHeap::node* p, bool isLeft) {
	if (p)
	{
		result += prefix;

		result += (isLeft ? "|--" : "|__");

		// print the key of the node
		result += to_string(p->key) + "\n";

		// enter the next tree level - left and right branch
		printRec(result, prefix + (isLeft ? "|   " : "    "), p->left, true);
		printRec(result, prefix + (isLeft ? "|   " : "    "), p->right, false);
	}
}


void LeftistHeap::print() {
	string result = "\n";
	printRec(result, "", root, false);

	menu.addResult(result);
}

void LeftistHeap::clear() {
	root = nullptr;
	menu.addResult("LeftistHeap has been cleaned");
}