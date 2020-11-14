#pragma once

#include <iostream>
#include <vector>
#include "../dataStructures/FirstDataStructure.h"
#include "../dataStructures/Stack.h"
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

