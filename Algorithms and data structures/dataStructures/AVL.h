#pragma once

#include "../core/DataStructureAbstract.h"

class AVL : public DataStructureAbstract {
private:
    const string name = "AVL";
    const string desc = "AVL";

    struct node {
        int value;
        int bl;
        node* left;
        node* right;
    };

    node* head = nullptr;
    
public:
    AVL();

    virtual void callback(string id, vector<int> params) override;

    void insert(int el);
    void deleteElem(int v);
    void isEmpty();

    node* Search(int v)
    {
        node* p = head;
        while (p && p->value != v)
        {
            if (v < p->value) p = p->left;
            else p = p->right;
        }
        return p;
    }
private:
    void Insert(int v, node*& root, bool& h);
    void Delete(int v, node*& root, bool& h);
    void RR(node* &p);
    void LL(node* &p);
    void RL(node* &p);
    void LR(node* &p);
};
