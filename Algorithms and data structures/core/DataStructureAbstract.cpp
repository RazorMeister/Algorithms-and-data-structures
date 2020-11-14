#include "DataStructureAbstract.h"

int DataStructureAbstract::STRUCTURES_NUM = 0;

DataStructureAbstract::DataStructureAbstract() {
    this->id = ++DataStructureAbstract::STRUCTURES_NUM;
    menu.setCallbackClass(this);
}

void DataStructureAbstract::setName(string name, string desc) {
    this->name = name;
    this->desc = desc;
    menu.setMeta(name, desc);
}

void DataStructureAbstract::start() {
    menu.run();
}

int DataStructureAbstract::getId() {
    return id;
}

string DataStructureAbstract::getName() {
    return name;
}

string DataStructureAbstract::getDesc() {
    return desc;
}