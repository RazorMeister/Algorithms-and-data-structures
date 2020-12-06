#pragma once

#include <iostream>
#include <vector>
#include "../dataStructures/Stack.h"
#include "../dataStructures/Queue.h"
#include "../dataStructures/UnorderedList.h"
#include "../dataStructures/OrderedList.h"
#include "../dataStructures/Heap.h"
#include "../dataStructures/BST.h"
#include "MenuStructure.h"

using namespace std;

class Gui : public ChoiceAbstract {
private:
    vector<DataStructureAbstract*> dataStructures;
    MenuStructure menu;
    void setMenu();
    void runStructure(int id);

public:
    Gui();

    void callback(string id, vector<int> params) override;
    void start();
};

