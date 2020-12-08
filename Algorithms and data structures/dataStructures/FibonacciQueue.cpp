#include "FibonacciQueue.h"
#include <string>

FibonacciQueue::FibonacciQueue() {
	setName(name, desc);

	menu.addChoice("1", "Insert", "O(1)", 1);
	menu.addChoice("2", "DeleteMax", "O(log n)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void FibonacciQueue::callback(string id, vector<int> params) {
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

void FibonacciQueue::putTree(FibonacciQueue::node*& main, FibonacciQueue::node* p) {
	if (main) {
		node* last = main->prev;
		last->next = p;
		p->next = nullptr;
		p->prev = last;
		main->prev = p;
	}
	else {
		main = p;
		main->prev = main;
		main->next = nullptr;
	}
}

FibonacciQueue::node* FibonacciQueue::popTree(FibonacciQueue::node*& main, string type) {
	if (main) {
		node* popped;

		// Single element in queue
		if (main->prev == main) {
			popped = main;
			main = nullptr;
		}
		else {
			if (type == "first") {
				popped = main;
				main = main->next;
				main->prev = popped->prev;
			}
			else {
				popped = main->prev;
				main->prev = popped->prev;
				popped->prev->next = nullptr;
			}
		}

		popped->prev = popped;
		popped->next = nullptr;


		return popped;
	}

	return nullptr;
}

FibonacciQueue::node* FibonacciQueue::qUnion(FibonacciQueue::node* p1, FibonacciQueue::node* p2) {
	node* p = p1;
		
	while (p2) {
		node* taken = popTree(p2, "first");
		if (!max || taken->val > max->val)
			max = taken;

		putTree(p, taken);
	}

	return p;
}

FibonacciQueue::node* FibonacciQueue::mergeTree(FibonacciQueue::node* p1, FibonacciQueue::node* p2) {
	if (p2->val > p1->val) {
		node* q = p1;
		p1 = p2;
		p2 = q;
	}

	if (p1->h == 0) {
		p1->child = p2;
	}
	else {
		node* last = p1->child->prev;
		p2->prev = last;
		last->next = p2;
		p1->child->prev = p2;
	}

	p1->h += 1;

	return p1;
}

void  FibonacciQueue::consolidate(FibonacciQueue::node*& head) {
	node* pArr[MAX] = {nullptr};

	while (head) {
		node* p = popTree(head, "first");
		while (pArr[p->h]) {
			p = mergeTree(p, pArr[p->h]);
			pArr[p->h - 1] = nullptr;
		}

		pArr[p->h] = p;
	}

	for (int i = 0; i < MAX; i++)
		if (pArr[i])
			putTree(head, pArr[i]);
}

void FibonacciQueue::insert(int el) {
	node* p = new node;
	p->val = el;
	p->next = nullptr;
	p->prev = p;
	p->child = nullptr;
	p->h = 0;
	p->mark = false;

	root = qUnion(root, p);

	menu.addResult("Success");
}

void FibonacciQueue::deleteMax() {
	if (!root) {
		menu.addResult("FibonacciQueue is empty");
		return;
	}

	menu.addResult("Deleted: " + to_string(max->val));

	// Single element
	if (root->prev == root) {
		root = nullptr;
	}
	else if (max == root) {
		max = popTree(root, "first");
	}
	else {
		max->prev->next = max->next;

		// Max is not the last el
		if (max->next)
			max->next->prev = max->prev;
		else
			root->prev = max->prev;
	}

	root = qUnion(root, max->child);
	consolidate(root);

	node* p = root;
	max = nullptr;

	while (p) {
		if (!max || p->val > max->val)
			max = p;
		p = p->next;
	}
}

void FibonacciQueue::isEmpty() {
	if (!root)
		menu.addResult("FibonacciQueue is empty");
	else
		menu.addResult("FibonacciQueue is NOT empty");
}

void FibonacciQueue::printRec(string& result, node* p) {
	if (p) {
		result += to_string(p->val) + " ";

		printRec(result, p->child);
		printRec(result, p->next);
	}
}

void FibonacciQueue::print() {
	string result = "\n";
	node* p = root;

	if (!root)
		return;

	result += "Max el: " + to_string(max->val) + "\n";

	while (p) {
		result += "Tree hight: " + to_string(p->h) + "\n";

		result += to_string(p->val) + " ";

		printRec(result, p->child);

		result += "\n\n";

		p = p->next;
	}

	menu.addResult(result);
}

void FibonacciQueue::clear() {
	root = nullptr;
	max = nullptr;
	menu.addResult("FibonacciQueue has been cleaned");
}