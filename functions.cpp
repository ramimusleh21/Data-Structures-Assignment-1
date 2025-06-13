#include <iostream>
#include "globals.h"
#include <cstdlib>
#include <string>

using namespace std;

FACTION ChooseFaction() {
	int RandomFaction = (rand() % 3) + 1;

	FACTION faction;

	switch (RandomFaction) {
	
	case 1: 
		faction = red;
		break;

	case 2: 
		faction = blue;
		break;
	
	case 3: 
		faction = green;
		break;
	}
	return faction;
}

string PrintFaction(FACTION faction) {
	switch (faction) {
	case 1: return "Red";
	case 2: return "Blue";
	case 3: return "Green";
	default: return "unknown";
	}
}

void PrintFullQueue(QUEUE* Q) {
	NODE* node = Q->head;

	if (node == NULL) {
		cout << "Queue is empty" << endl;
	}
	int count = 0;
	cout << endl;

	while (node) {
		count++;
		cout << "____________________________________"<< endl;
		cout << "*** User " << count << " ***" << endl;
		cout << "Username: " << node->user.username << endl;
		cout << "Level: " << node->user.lvl << endl;
		cout << "Faction: " << PrintFaction(node->user.faction) << endl;

		node = node->next;
	}
}

void PrintUser(NODE* node) {
	cout << "____________________________________" << endl;
	cout << "Username: " << node->user.username << endl;
	cout << "Level: " << node->user.lvl << endl;
	cout << "Faction: " << PrintFaction(node->user.faction) << endl;
	cout << "____________________________________" << endl;
}

void PrintUserName(NODE* node) {
	cout << node->user.username << endl;
}

string SelectRandomNamePart(string* list) {
	int Selection = rand() % NameListSize;
	return list[Selection];
}

string SelectRandomNumber() {
	return to_string((rand() % 100) + 1);

}

string ChooseUserName() {

	string FirstPartList[NameListSize] = {
	"Big", "Small", "Round", "Furry", "Angry",
	"Tiny", "Loud", "Brave", "Swift", "Happy",
	"Sleepy", "Lazy", "Wild", "Clever", "Sneaky",
	"Bold", "Fast", "Giant", "Chubby", "Crazy"
	};

	string SecondPartList[NameListSize] = {
		"Red", "Purple", "Green", "Blue", "Brown",
		"Black", "White", "Orange", "Yellow", "Pink",
		"Teal", "Gray", "Golden", "Silver", "Maroon",
		"Navy", "Cyan", "Olive", "Violet", "Amber"
	};

	string ThirdPartList[NameListSize] = {
		"Elephant", "Penguin", "Puppy", "Cat", "Hamster",
		"Tiger", "Lion", "Bear", "Wolf", "Fox",
		"Giraffe", "Monkey", "Zebra", "Rabbit", "Koala",
		"Panda", "Owl", "Hawk", "Frog", "Goat"
	};

	string PartOne = SelectRandomNamePart(FirstPartList);
	string PartTwo = SelectRandomNamePart(SecondPartList);
	string PartThree = SelectRandomNamePart(ThirdPartList);
	string PartFour = SelectRandomNumber();

	return PartOne + PartTwo + PartThree + PartFour;
}


int ChooseLvl() {
	return (rand() % 60) + 1;
}

