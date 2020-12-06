#include "BST.h"
#include <string>

BST::BST() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(log(n))", 1);
	menu.addChoice("2", "Delete", "O(log(n))", 1);
	menu.addChoice("3", "IsEmpty", "O(1)");
}

void BST::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
			case 1:
				insert(params[0]);
				break;
			case 2:
				Delete(params[0]);
				break;
			case 3:
				isEmpty();
				break;
			default:
				break;
		}

		cout << endl;
	}
	catch (...) {
	}
}

void BST::insert(int el) {
	node** p = Search(el);
	if (*p) return;

	*p = new node;
	(*p)->value = el;
	(*p)->left = (*p)->right = nullptr;

	menu.addResult("Success");
}

void BST::Delete(int v) 
{
	node* pv, ** q, ** p = Search(v);
	if (*p) 
	{
		if ((*p)->left && (*p)->right)
		{
			int rnd = int(2.0 * (double(rand()) / (double(RAND_MAX) + 1.0)));
			if (rnd == 0)
			{
				q = &((*p)->left);
				while((*q)->right) q = &((*q)->right);
			}
			else
			{
				q = &((*p)->right);
				while ((*q)->left) q = &((*q)->left);
			}
			pv = *q;
			(*p)->value = pv->value;
			if (rnd == 0) *q = pv->left;
			else *q = pv->right;
		}
		else
		{
			pv = *p;
			if ((*p)->left == nullptr) *p = (*p)->left;
			else *p = (*p)->right;
		}
		if (pv)
		{
			menu.addResult("Deleted: " + to_string(pv->value));
			delete pv;
		}
		else menu.addResult("BST is empty");
	}
	menu.addResult("Value not exist");
}

void BST::isEmpty() {
	if (!head)
		menu.addResult("BST is empty");
	else
		menu.addResult("BST is NOT empty");
}