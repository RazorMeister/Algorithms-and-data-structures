#pragma once

#include "../core/DataStructureAbstract.h"

class BST : public DataStructureAbstract {
private:
    const string name = "BST";
    const string desc = "BST";

    struct node {
        int value;
        node* left;
        node* right;
    };

    node* head = nullptr;
    
public:
    BST();

    virtual void callback(string id, vector<int> params) override;

    void insert(int el);
    void Delete(int v);
    void isEmpty();

    node** Search(int v)
    {
        node** p = &head;
        while ((*p) && (*p)->value != v)
        {
            if (v > (*p)->value) p = &((*p)->right);
            else  p = &((*p)->left);
        }
        return p;
    }
};
