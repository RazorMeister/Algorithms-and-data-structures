#pragma once

#include "../core/DataStructureAbstract.h"

class OrderedList : public DataStructureAbstract {
private:
    const string name = "OrderedList";
    const string desc = "OrderedList";

    struct node {
        int value;
        node* next;
    };

    node* head = nullptr;
    
public:
    OrderedList();

    virtual void callback(string id, vector<int> params) override;

    void insert(int el);
    void max();
    void deleteMax();
    void isEmpty();
    void print();
    void clear();
};
