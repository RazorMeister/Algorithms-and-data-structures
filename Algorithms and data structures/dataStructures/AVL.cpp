#include "AVL.h"
#include <string>

AVL::AVL() { 
	setName(name, desc); 

	menu.addChoice("1", "Insert", "O(log(n))", 1);
	menu.addChoice("2", "Delete", "O(log(n))", 1);
	menu.addChoice("3", "IsEmpty", "O(1)");
}

void AVL::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		switch (idInt) {
			case 1:
				insert(params[0]);
				break;
			case 2:
				deleteElem(params[0]);
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

void AVL::insert(int el) {
	bool hchange = false;
	Insert(el, head, hchange);

	menu.addResult("Success");
}

void AVL::Insert(int v, node*& root, bool& h)
{
	node* p;
	if (!root)
	{
		root = new node;
		root->value = v;
		root->left = root->right = NULL;
		root->bl = 0;
		h = true;
		return;
	}

	if (v < root->value)
	{
		Insert(v, root->left, h);
		if (h)
		{
			switch (root->bl)
			{
			case 1:
				p = root->left;
				if (p->bl == 1 || p->bl == 0) LL(root);
				else LR(root);
				h = false;
				break;
			case 0:
				root->bl = 1;
				break;
			case -1:
				root->bl = 0;
				h = false;
				break;
			}
		}
		return;
	}

	if (v > root->value)
	{
		Insert(v, root->right, h);
		if (h)
		{
			switch (root->bl)
			{
			case 1:
				root->bl = 0;
				h = false;
				break;
			case 0:
				root->bl = -1;
				break;
			case -1:
				p = root->right;
				if (p->bl == -1 || p->bl == 0) RR(root);
				else RL(root);
				h = false;
				break;
			}
		}
	}
}

void AVL::deleteElem(int v) 
{
	bool hchange = false;
	Delete(v, head, hchange);
}

void AVL::Delete(int v, node*& root, bool& h)
{
	bool done = false;
	if (!root)
	{
		h = false;
		done = true;
	}
	else if (v < root->value)
	{
		Delete(v, root->left, h);
		if (h)
		{
			if (root->bl >= 0)
			{
				root->bl--;
				if (root->bl == -1) h = false;
			}
			else
			{
				if (root->right->bl == -1) RR(root);
				else RL(root);
			}
			done = true;
		}
	}
	else if (v == root->value)
	{
		menu.addResult("Deleted: " + to_string(v));
		if (!root->left || !root->right)
		{
			node* x;
			if (!root->left) x = root->right;
			else x = root->left;
			delete root;
			root = x;
			h = true;
			done = true;
		}
		else
		{
			node* y = root->right;
			while (y->left) y = y->left;
			root->value = y->value;
			v = root->value;
		}
	}

	if (!done && v >= root->value)
	{
		Delete(v, root->right, h);
		if (h)
		{
			if (root->bl <= 0)
			{
				root->bl++;
				if (root->bl == 1) h = false;
			}
			else
			{
				if (root->left->bl == 1) LL(root);
				else LR(root);
			}
		}
	}

}

void AVL::isEmpty() {
	if (!head)
		menu.addResult("AVL is empty");
	else
		menu.addResult("AVL is NOT empty");
}

void AVL::RR(node*& p)
{
	node* x = p->right;
	p->right = x->left;
	x->left = p;
	p->bl = (x->bl == -1) ? 0 : -1;
	x->bl = (x->bl == 0) ? 1 : 0;
	p = x;
}

void AVL::LL(node*& p)
{
	node* x = p->left;
	p->left = x->right;
	x->right = p;
	p->bl = (x->bl == 1) ?  0 : 1;
	x->bl = (x->bl == 0) ? -1 : 0;
	p = x;
}

void AVL::RL(node*& p)
{
	LL(p->right);
	RR(p);
}

void AVL::LR(node*& p)
{
	RR(p->left);
	LL(p);
}