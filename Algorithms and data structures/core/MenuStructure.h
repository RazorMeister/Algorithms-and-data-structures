#pragma once

#include <iostream>
#include <vector>
#include "ChoiceAbstract.h"

using namespace std;

class MenuStructure {
private:
    struct choice {
        string id;
        string name;
        string desc;
        int paramsCount;
    };

    string menuName = "";
    string menuDesc = "";
    
    ChoiceAbstract* callbackClass;

    vector<choice*> choices;

    void printMeta();
    void printChoices();
    void printChoice(string id);

    choice* getChoice(string id);
    vector<int> handleChoiceParams(choice* ch);
public:
    MenuStructure();

    void setMeta(string menuName, string menuDesc = "");
    void setCallbackClass(ChoiceAbstract* callbackClass);
    void addChoice(string id, string name, string desc = "", int paramsCount = 0);
    void addChoice(int id, string name, string desc = "", int paramsCount = 0);
    void run();
};

