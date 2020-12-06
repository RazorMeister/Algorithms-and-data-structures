#include "Beap.h"
#include <string>

Beap::Beap() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(sqrt n)", 1);
	menu.addChoice("2", "Search", "O(sqrt n)", 1);
	menu.addChoice("3", "DeleteMax", "O(sqrt n)");
	menu.addChoice("4", "IsEmpty", "O(1)");
	menu.addChoice("5", "Print", "O(n)");
	menu.addChoice("6", "Clear", "Reset all data");
}

void Beap::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
			case 1:
				insert(params[0]);
				break;
			case 2:
				search(params[0]);
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

int Beap::ij2k(int i, int j) {
	return (i * (i - 1)) / 2 + j;
}

int* Beap::k2ij(int k) {
	int i = int(ceil(0.5 * (-1 + sqrt(1.0 + 8 * k))));

	return new int[2]{
		i,
		int(k - 0.5 * i * (i - 1))
	};
}

void Beap::upBeap(int k) {
	int x = H[k];
	int* ij = k2ij(k);
	int i = ij[0];
	int j = ij[1];
	int k1 = k;

	while (i > 1) {
		if (j == 1) {
			k = k-i + 1;
		}	
		else if (j == i) {
			k -= i;
			j--;
		}
		else {
			k -= i;
			j--;

			if (H[k + 1] < H[k]) {
				k++;
				j++;
			}
		}

		if (H[k] < x) {
			H[k1] = H[k];
			k1 = k;
			i--;
		}
		else
			break;
	}

	H[k1] = x;

}

void Beap::downBeap(int k) {
	int x = H[k];
	int* ij = k2ij(k);
	int i = ij[0];
	int k1 = k;
	k += i;
	i++;

	while (k <= hl) {
		if (k < hl && H[k + 1] > H[k])
			k++;

		if (H[k] > x) {
			H[k1] = H[k];
			k1 = k;
			k += i;
			i++;
		}
		else
			break;
	}

	H[k1] = x;
}

void Beap::insert(int el) {
	hl++;
	H[hl] = el;
	upBeap(hl);

	menu.addResult("Success");
}

void Beap::search(int el) {
	int k = hl;
	int* ij = k2ij(k);
	int i = ij[0];
	int j = ij[1];

	if (i != j) {
		i--;
		j = i;
		k = ij2k(i, j);
	}

	while (H[k] != el && j > 0) {
		if (el > H[k]) { // NW
			i--;
			j--;
			k = ij2k(i, j);
		}
		else { // el < H[K]
			if (ij2k(i + 1, j) <= hl) { // SW
				i++;
				k = ij2k(i, j);
			}
			else { // W
				j--;
				k--;
			}
		}
	}

	if (H[k] == el)
		menu.addResult("Element found!");
	else
		menu.addResult("Element NOT found!");
}

void Beap::deleteMax() {
	if (hl > 0) {
		menu.addResult("Deleted: " + to_string(H[1]));

		H[1] = H[hl];
		hl--;
		downBeap(1);
	}
	else {
		menu.addResult("Beap is empty");
	}
}

void Beap::isEmpty() {
	if (hl == 0)
		menu.addResult("Beap is empty");
	else
		menu.addResult("Beap is NOT empty");
}


void Beap::print() {
	string result = "\n";

	int levels = (int)sqrt(hl);
	int size = (levels + 1) * 2 + (levels + 2) * 4;
	int lvl = -1;

	for (int i = 1; i <= hl; i++) {
		int* ij = k2ij(i);

		if (lvl != ij[0]) {
			result += "\n";
			lvl = ij[0];
		}
		
		int spacesCount = (size - lvl * 2) / (lvl + 1);
		for (int j = 0; j < spacesCount; j++)
			result += " ";

		result += to_string(H[i]);
	}
		
	menu.addResult(result);
}

void Beap::clear() {
	hl = 0;
	menu.addResult("Beap has been cleaned");
}