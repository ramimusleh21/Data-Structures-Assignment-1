#include <iostream>
#include "functions.h"
#include "globals.h"

using namespace std;


QUEUE* initializeQueue() {
	QUEUE* newQueue = (QUEUE*)malloc(sizeof(QUEUE));

	if (newQueue == NULL) {
		perror("Error: Could Not Allocate Space");
		exit(EXIT_FAILURE);
	}

	newQueue->size = 0;
	newQueue->head = NULL;
	newQueue->tail = NULL;

	return newQueue;
}

int QueueSize(QUEUE& Q) {
	return Q.size;
}

bool Enqueue(QUEUE* Q) {
	NODE* newNode = new NODE();

	if (newNode == NULL) {
		perror("Error: Could Not Allocate Space");
		return false;
	}

	newNode->user.username = ChooseUserName();
	newNode->user.lvl = ChooseLvl();
	newNode->user.faction = ChooseFaction();
	newNode->next = NULL;

	while (CompareNames(newNode->user.username)) {
		newNode->user.username = ChooseUserName();
	}

	usernameList.push_back(newNode->user.username);

	if (IsEmpty(Q)) {
		Q->head = newNode;
		Q->tail = newNode;
	}
	else {
		Q->tail->next = newNode;
		Q->tail = newNode;

	}
	Q->size++;
	return true;
}


void Peek(NODE* node) {
	cout << endl;

	if (node == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}

	PrintUser(node);
	

}

void Pop(Queue* Q) {
	cout << endl;

	if (Q->head == NULL) {
		cout << "Queue is empty" << endl;
		return;
	}

	NODE* node = Q->head;

	while (node) {
		PrintUser(node);
		NODE* temp = node;
		node = node->next;
		Dequeue(Q, 1);
	}
	cout << "\n***All Users Removed***" << endl;
}

void Dequeue(QUEUE* Q, int selection) {

	if (IsEmpty(Q)) {
		cout << "Queue is empty" << endl;
		return;
	}

	NODE* node = Q->head;
	int count = 0;
	while (node) {
		count++;
		node = node->next;
	}

	if (selection > count) {
		cout << "\nThere are only " << count << " users" << endl;
		return;
	}

	else if (selection < 1) {
		cout << "\nInvalid Option" << endl;
		return;
	}

	node = Q->head;

	if (selection == 1) {
		NODE* temp = node;
		Q->head = node->next;
		node = node->next;
		delete(temp);
	}

	else if(selection == Q->size){
		NODE* prev = node;

		for (int i = 1; i < selection; i++) {
			node = node->next;
			if (node->next != NULL) {
				prev = node;
			}
		}
		prev->next = NULL;
		Q->tail = prev;
		delete(node);
	}

	else {
		NODE* prev = node;

		for (int i = 1; i < selection; i++) {
			node = node->next;
			if (i != selection - 1) {
				prev = node;
			}
		}

		prev->next = node->next;
		delete(node);

	}
	cout << "\nUser Deleted" << endl;
	Q->size--;
}

void DeleteQueue(QUEUE* Q) {
	NODE* node = Q->head;
	
	while (node) {
		NODE* temp = node;
		node = node->next;
		delete(temp);
	}

	free(Q);
}

bool IsEmpty(QUEUE* Q) {
	return Q->head == NULL;
}