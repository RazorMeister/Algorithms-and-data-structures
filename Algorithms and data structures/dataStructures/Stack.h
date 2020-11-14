#pragma once

#include "../core/DataStructureAbstract.h"

class Stack : public DataStructureAbstract {
private:
    const string name = "Stack";
    const string desc = "Stack is something very very good";

    int stack[MAX_ELEMENTS];
    int top = -1;
    
public:
    Stack();

    virtual void callback(string id, vector<int> params) override;

    void push(int el);
    void pop();
    void isEmpty();
    void print();
    void clear();
};
