#pragma once

#define MAX_ELEMENTS 10

#include <iostream>
#include "MenuStructure.h"

using namespace std;

class DataStructureAbstract : public ChoiceAbstract{
protected:
    int id;
    string name;
    string desc;
    
    MenuStructure menu;

    void setName(string name, string desc = "");

public:
    static int STRUCTURES_NUM;

    DataStructureAbstract();
    
    virtual void callback(string id, vector<int> params) override = 0;
    void start();

    int getId();
    string getName();
    string getDesc();
};

