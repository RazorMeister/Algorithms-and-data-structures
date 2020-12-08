#include "BinomialQueue.h"
#include <string>

BinomialQueue::BinomialQueue() {
	setName(name, desc);

	menu.addChoice("1", "Insert", "O(log n)", 1);
	menu.addChoice("2", "DeleteMax", "O(log n)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void BinomialQueue::callback(string id, vector<int> params) {
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

void BinomialQueue::putTree(BinomialQueue::node*& main, BinomialQueue::node* p) {
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

BinomialQueue::node* BinomialQueue::popTree(BinomialQueue::node*& main, string type) {
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

BinomialQueue::node* BinomialQueue::qUnion(BinomialQueue::node* p1, BinomialQueue::node* p2) {
	node* p = nullptr;
	int i = 0;
	node* popped[2] = { nullptr, nullptr };
	int lastH = -1;

	while (p1 || p2) {
		if (p1) {
			if (p1->h == i) {
				popped[0] = popTree(p1, "first");
			}
		}

		if (p2) {
			if (p2->h == i) {
				popped[1] = popTree(p2, "first");
			}
		}

		if (p)
			lastH = p->h;

		// No tree
		if (!popped[0] && !popped[1]) {
			
		}
		else if (popped[0] && !popped[1]) { // Tree only in p1
			if (lastH == i) { // Tree with i height is already on the queue
				node* lastTree = popTree(p, "last");
				putTree(p, mergeTree(popped[0], lastTree));
			}
			else
				putTree(p, popped[0]);
		}
		else if (!popped[0] && popped[1]) { // Tree only in p2
			if (lastH == i) { // Tree with i height is already on the queue
				node* lastTree = popTree(p, "last");
				putTree(p, mergeTree(popped[1], lastTree));
			}
			else
				putTree(p, popped[1]);
		}
		else { // Tree in p1 and p2
			putTree(p, mergeTree(popped[0], popped[1]));
		}

		popped[0] = nullptr;
		popped[1] = nullptr;
		lastH = -1;
		i++;
	}

	return p;
}

BinomialQueue::node* BinomialQueue::mergeTree(BinomialQueue::node* p1, BinomialQueue::node* p2) {
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

void BinomialQueue::insert(int el) {
	node* p = new node;
	p->val = el;
	p->next = nullptr;
	p->prev = p;
	p->child = nullptr;
	p->h = 0;

	root = qUnion(root, p);

	menu.addResult("Success");
}

void BinomialQueue::deleteMax() {
	if (!root) {
		menu.addResult("BinomialQueue is empty");
		return;
	}

	node* p = root;
	node* pMax = root;
	while (p) {
		if (p->val > pMax->val)
			pMax = p;
		p = p->next;
	}

	node* t = pMax->child;

	if (pMax->next)
		pMax->next->prev = pMax->prev;
	else
		root->prev = pMax->prev;

	if (pMax != root)
		pMax->prev->next = pMax->next;
	else
		root = root->next;

	root = qUnion(root, t);
	
	menu.addResult("Deleted: " + to_string(pMax->val));
}

void BinomialQueue::isEmpty() {
	if (!root)
		menu.addResult("BinomialQueue is empty");
	else
		menu.addResult("BinomialQueue is NOT empty");
}

void BinomialQueue::printRec(string& result, node* p) {
	if (p) {
		result += to_string(p->val) + " ";

		printRec(result, p->child);
		printRec(result, p->next);
	}
}

void BinomialQueue::print() {
	string result = "\n";
	node* p = root;

	while (p) {
		result += "Tree hight: " + to_string(p->h) + "\n";

		result += to_string(p->val) + " ";

		printRec(result, p->child);

		result += "\n\n";

		p = p->next;
	}

	menu.addResult(result);
}

void BinomialQueue::clear() {
	root = nullptr;
	menu.addResult("BinomialQueue has been cleaned");
}