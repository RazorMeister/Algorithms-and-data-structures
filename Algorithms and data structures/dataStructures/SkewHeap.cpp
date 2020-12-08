#include "SkewHeap.h"
#include <string>

SkewHeap::SkewHeap() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(n)", 1);
	menu.addChoice("2", "DeleteMax", "O(n)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void SkewHeap::callback(string id, vector<int> params) {
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

SkewHeap::node* SkewHeap::hUnion(SkewHeap::node *p1, SkewHeap::node *p2) {
	node* p;

	if (!p1)
		return p2;
	if (!p2)
		return p1;

	if (p1->key > p2->key) {
		p = p1;
		p->right = hUnion(p->right, p2);
	}
	else {
		p = p2;
		p->right = hUnion(p->right, p1);
	}

	node* q = p->left;
	p->left = p->right;
	p->right = q;

	return p;
}

void SkewHeap::insert(int el) {
	node* p = new node;
	p->key = el;
	p->left = p->right = nullptr;

	root = hUnion(root, p);

	menu.addResult("Success");
}

void SkewHeap::deleteMax() {
	if (!root) {
		menu.addResult("SkewHeap is empty");
	}
	else {
		menu.addResult("Deleted: " + to_string(root->key));
		root = hUnion(root->left, root->right);
	}
}

void SkewHeap::isEmpty() {
	if (!root)
		menu.addResult("SkewHeap is empty");
	else
		menu.addResult("SkewHeap is NOT empty");
}

void SkewHeap::printRec(string &result, string prefix, SkewHeap::node* p, bool isLeft) {
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


void SkewHeap::print() {
	string result = "\n";
	printRec(result, "", root, false);

	menu.addResult(result);
}

void SkewHeap::clear() {
	root = nullptr;
	menu.addResult("SkewHeap has been cleaned");
}