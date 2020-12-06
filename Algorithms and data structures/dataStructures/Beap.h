#pragma once

#include "../core/DataStructureAbstract.h"

#define MAX 200

class Beap : public DataStructureAbstract {
private:
    const string name = "Beap";
    const string desc = "Beap";

    // Elements begin from H[1]
    int H[MAX];

    // Last heap element
    int hl = 0;
    
public:
    Beap();

    virtual void callback(string id, vector<int> params) override;

    // Should be private but it's public
    int ij2k(int i, int j);
    int* k2ij(int k);

    void upBeap(int i);
    void downBeap(int i);

    void insert(int el);
    void search(int el);
    void deleteMax();

    void isEmpty();
    void print();
    void clear();
};
