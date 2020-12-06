#pragma once

#include "../core/DataStructureAbstract.h"

#define MAX 200

class Heap : public DataStructureAbstract {
private:
    const string name = "Heap";
    const string desc = "UpHeap - O(log n) | DownHeap - O(log n)\n\t ConstructUp - O(n log n) | ConstructDown - O(n)";


    // H[0] - guard
    // Elements begin from H[1]
    int H[MAX];

    // Last heap element
    int hl = 0;
    
public:
    Heap();

    virtual void callback(string id, vector<int> params) override;

    void upHeap(int i);
    void downHeap(int i);

    void insert(int el);
    void deleteMax();

    void isEmpty();
    void print();
    void clear();
};
