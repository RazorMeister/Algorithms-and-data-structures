#pragma once

#include "../core/DataStructureAbstract.h"

class UnorderedList : public DataStructureAbstract {
private:
    const string name = "UnorderedList";
    const string desc = "UnorderedList";

    struct node {
        int value;
        node* next;
    };

    node* head = nullptr;
    
public:
    UnorderedList();

    virtual void callback(string id, vector<int> params) override;

    void insert(int el);
    void max();
    void deleteMax();
    void isEmpty();
    void print();
    void clear();
};
