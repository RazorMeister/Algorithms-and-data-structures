#include "Heap.h"
#include <string>

Heap::Heap() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(log n)", 1);
	menu.addChoice("2", "DeleteMax", "O(log n)");
	menu.addChoice("3", "IsEmpty", "O(1)");
	menu.addChoice("4", "Print", "O(n)");
	menu.addChoice("5", "Clear", "Reset all data");
}

void Heap::callback(string id, vector<int> params) {
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

void Heap::upHeap(int i) {
	H[0] = INT_MAX;
	int v = H[i];

	while (H[i / 2] < v) {
		H[i] = H[i / 2];
		i = i / 2;
	}

	H[i] = v;
}

void Heap::downHeap(int i) {
	while (2 * i <= hl) {
		int k = 2 * i;

		if (k + 1 <= hl && H[k + 1] > H[k])
			k++;

		if (H[k] <= H[i])
			break;

		swap(H[i], H[k]);
		i = k;
	}
}

void Heap::insert(int el) {
	hl++;
	H[hl] = el;
	upHeap(hl);

	menu.addResult("Success");
}

void Heap::deleteMax() {
	if (hl > 0) {
		menu.addResult("Deleted: " + to_string(H[1]));

		H[1] = H[hl];
		hl--;
		downHeap(1);
	}
	else {
		menu.addResult("Heap is empty");
	}
}

void Heap::isEmpty() {
	if (hl == 0)
		menu.addResult("Heap is empty");
	else
		menu.addResult("Heap is NOT empty");
}


void Heap::print() {
	string result = "\n";
	int lvl = 1;

	int levels = (int)log2(hl);
	int size = pow(2, levels) * 2 + (pow(2, levels) + 2) * 4;

	for (int i = 1; i <= hl; i++) {
		if (pow(2, lvl) <= i) {
			lvl++;
			result += "\n";
		}
		
		int spacesCount = (size - pow(2, lvl - 1)*2) / (pow(2, lvl - 1) + 1);
		for (int j = 0; j < spacesCount; j++)
			result += " ";

		result += to_string(H[i]);
	}
		
	menu.addResult(result);
}

void Heap::clear() {
	hl = 0;
	menu.addResult("Heap has been cleaned");
}