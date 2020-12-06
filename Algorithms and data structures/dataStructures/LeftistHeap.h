#pragma once

#include "../core/DataStructureAbstract.h"

#define MAX 200

class LeftistHeap : public DataStructureAbstract {
private:
    const string name = "LeftistHeap";
    const string desc = "LeftistHeap";

    struct node {
        int key;
        node* left, * right;
        int npl;
    };

    node* root;
    
    void printRec(string &result, string prefix, node* p, bool isLeft);

public:
    LeftistHeap();

    virtual void callback(string id, vector<int> params) override;

    node* hUnion(node *p1, node *p2);

    void insert(int el);
    void deleteMax();

    void isEmpty();
    void print();
    void clear();
};
