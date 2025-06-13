#pragma once
#include <vector>


const int NameListSize = 20;


using namespace std;

extern vector<string> usernameList;

enum faction { red = 1, blue = 2, green = 3 };
typedef faction FACTION;


typedef struct user {
	string username;
	int lvl;
	FACTION faction;

	user() : username(""), lvl(0), faction(red){}
}USER;


typedef struct QueueNode {
	USER user;
	struct QueueNode* next;
}NODE;


typedef struct Queue {
	NODE* head;
	NODE* tail;
	int size;

}QUEUE;
