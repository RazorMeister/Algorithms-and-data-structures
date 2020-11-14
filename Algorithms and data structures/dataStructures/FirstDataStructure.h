#pragma once

#include "../core/DataStructureAbstract.h"

class FirstDataStructure : public DataStructureAbstract {
private:
    const string name = "First Data Structure";
    const string desc = "First Data Structure DESC";

public:
    FirstDataStructure() { setName(name, desc); menu.addChoice("1", "Pierwszy"); }
    virtual void callback(string id, vector<int> params) override;
};

