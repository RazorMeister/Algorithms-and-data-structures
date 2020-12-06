#pragma once

#include "../core/DataStructureAbstract.h"

class Queue : public DataStructureAbstract {
private:
    const string name = "Queue";
    const string desc = "Queue";

    struct node {
        int value;
        node* next;
    };

    node* head = nullptr;
    
public:
    Queue();

    virtual void callback(string id, vector<int> params) override;

    void put(int el);
    void get();
    void isEmpty();
    void print();
    void clear();
};
