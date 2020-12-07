#pragma once

#include "../core/DataStructureAbstract.h"

#define MAX 200

class BinomialQueue : public DataStructureAbstract {
private:
    const string name = "BinomialQueue";
    const string desc = "BinomialQueue";

    struct node {
        int val;
        int h;
        node* prev, * next, *child;

        int mark;
    };

    node* root;
    
    void printRec(string &result, node* p);

    void putTree(node* &main, node* p);
    node * popTree(node* &main, string type);

public:
    BinomialQueue();

    virtual void callback(string id, vector<int> params) override;

    node* qUnion(node *p1, node *p2);
    node* mergeTree(node *p1, node *p2);

    void insert(int el);
    void deleteMax();

    void isEmpty();
    void print();
    void clear();
};
