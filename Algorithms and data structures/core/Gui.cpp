#include "Gui.h"
#include <algorithm>
#include <string>

Gui::Gui() {
    dataStructures.push_back(new Stack());
    dataStructures.push_back(new Queue());
    dataStructures.push_back(new UnorderedList());
    dataStructures.push_back(new OrderedList());
    dataStructures.push_back(new Heap());
    dataStructures.push_back(new Beap());
    dataStructures.push_back(new LeftistHeap());
    dataStructures.push_back(new SkewHeap());
    dataStructures.push_back(new BinomialQueue());
	dataStructures.push_back(new BST());
	dataStructures.push_back(new AVL());

	setMenu();
}

void Gui::callback(string id, vector<int> params) {
	try {
		int idInt = stoi(id);
		runStructure(idInt);
	}
	catch (...) {
	}
}

void Gui::setMenu() {
	menu.setMeta("GUI", "Algorithms and data structures | MINI PW 2020");
	menu.setCallbackClass(this);

	for_each(dataStructures.begin(), dataStructures.end(), [this](DataStructureAbstract* structure) {
		menu.addChoice(to_string(structure->getId()), structure->getName(), structure->getDesc());
		});
}

void Gui::start() {
	menu.run();
}

void Gui::runStructure(int id) {
	id--;
	if (id >= 0 && id < dataStructures.size())
		dataStructures[id]->start();
}