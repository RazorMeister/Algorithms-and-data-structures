#pragma once

#include "../core/DataStructureAbstract.h"

#define MAX 200

class FibonacciQueue : public DataStructureAbstract {
private:
    const string name = "FibonacciQueue";
    const string desc = "FibonacciQueue without marks";

    struct node {
        int val;
        int h;
        node* prev, * next, *child;

        bool mark;
    };

    node* root;
    node* max = nullptr;
    
    void printRec(string &result, node* p);

    void putTree(node* &main, node* p);
    node * popTree(node* &main, string type);

public:
    FibonacciQueue();

    virtual void callback(string id, vector<int> params) override;

    node* qUnion(node *p1, node *p2);
    void consolidate(node* & head);
    node* mergeTree(node* p1, node* p2);

    void insert(int el);
    void deleteMax();

    void isEmpty();
    void print();
    void clear();
};
