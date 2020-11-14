#include "MenuStructure.h"
#include <algorithm>
#include <string>

MenuStructure::MenuStructure() {
	choices.push_back(new choice{"q", "Exit", ""});
}

void MenuStructure::setMeta(string menuName, string menuDesc) {
	this->menuName = menuName;
	this->menuDesc = menuDesc;
}

void MenuStructure::setCallbackClass(ChoiceAbstract* callbackClass) {
	this->callbackClass = callbackClass;
}

void MenuStructure::addChoice(string id, string name, string desc, int paramsCount) {
	choices.push_back(new choice{id, name, desc, paramsCount});
}

void MenuStructure::addChoice(int id, string name, string desc, int paramsCount) {
	addChoice(to_string(id), name, desc, paramsCount);
}

 void MenuStructure::run() {
	 string ch;

	 do {
		 printMeta();
		 printChoices();
		 cin >> ch;
		 system("cls");
		 auto chosen = getChoice(ch);
		 
		 if (chosen) {
			 cout << "Your choice: ";
			 printChoice(ch);

			 callbackClass->callback(ch, handleChoiceParams(chosen));
		 }
		 else {
			 printChoice(ch);
		 }
		 
	 } while (ch != "q");
 }

 vector<int> MenuStructure::handleChoiceParams(choice* ch) {
	vector<int> params;

	for (int i = 0; i < ch->paramsCount; i++) {
		cout << "> Write parameter num: " << i+1 << ": ";
		int param;
		cin >> param;
		params.push_back(param);
	}

	return params;
 }

MenuStructure::choice* MenuStructure::getChoice(string id) {
	 choice* found = nullptr;

	 for_each(choices.begin(), choices.end(), [id, &found](choice* c) {
		 if (c->id == id)
			 found = c;
		 });

	 return found;
 }

 void MenuStructure::printMeta() {
	 if (menuName != "") {
		 cout << menuName;
		 
		 if (menuDesc != "")
			 cout << " - " << menuDesc;

		 cout << endl << endl;
	 }
 }

 void MenuStructure::printChoice(string id) {
	 bool found = false;

	 for_each(choices.begin(), choices.end(), [id, &found](choice* c) {
		 if (c->id == id) {
			 cout << "Id: " << c->id;
			 cout << " | Name: " << c->name << endl << endl;
			 found = true;
		 }
	});

	 if (!found)
		 cout << "<id not found>" << endl << endl;
 }

 void MenuStructure::printChoices() {
	 for_each(choices.begin(), choices.end(), [](choice* c) {
		 cout << "\tId: " << c->id << endl;
		 cout << "\tName: " << c->name << endl;
		 if (c->desc != "") cout << "\tDesc: " << c->desc << endl;
		 if (c->paramsCount > 0) cout << "\tParamsCount: " << c->paramsCount << endl;
		 cout << endl;
	});
 }
