#include <iostream>
#include <cstdlib>
#include "globals.h"
#include "functions.h"
#include "QueueOperations.h"

using namespace std;

int main(void) {
	srand(time(0));

	QUEUE* queue = initializeQueue();

	if (queue == NULL) {
		cout << "Queue is NULL!\n";
		exit(EXIT_FAILURE);
	}

	int QueueLimit;
	cout << "How Many Users Should be in the Queue (max 20): ";
	cin.clear();

	while (true) {
		if (cin >> QueueLimit) break;

		cout << "Enter a valid number: ";
		cin.clear();
		cin.ignore(150, '\n');
	}

	if (QueueLimit > 20) {
		QueueLimit = 20;
	}
	else if(QueueLimit < 1) {
		QueueLimit = 5;
	}

	for (int i = 1; i <= QueueLimit; i++) {
		Enqueue(queue);
	}

	cout << endl;
	cout << QueueLimit << " User(s) Created" << endl;
	cout << "The Queue Limit is "  << QueueLimit << endl;
	cout << endl;

	bool ProgramOn = true;
	int choice;

	while (ProgramOn) {
		cout << "\n *** MAIN MENU ***\n" << endl;
		cout << "1. Add To Queue" << endl;
		cout << "2. Remove From Queue" << endl;
		cout << "3. Peek Queue" << endl;
		cout << "4. Print Full Queue" << endl;
		cout << "5. Reset Queue" << endl;
		cout << "6. Exit" << endl;
		cout << "\nChoose An Option: ";
		cin >> choice;
		cout << endl;

		switch (choice) {
		case 1: 
			if (queue->size == QueueLimit) {
				cout << "\n\nThe Queue is at it's limit" << endl;
				cout << "Please Remove a User, or reset the queue" << endl;
			}
			else {
				cout << "\n\n*** ADD TO QUEUE ***\n";
				Enqueue(queue);
				cout << "User Created" << endl;
			}
			break;

		case 2: 
			cout << "\n\n*** REMOVE FROM QUEUE ***\n";
			Dequeue(queue);
			break;

		case 3:
			cout << "\n\n*** PEEK ***\n";
			Peek(queue->head);
			break;

		case 4:
			cout << "\n\n***PRINT FULL QUEUE ***\n";
			PrintFullQueue(queue);
			break;

		case 5:
			cout << "\n\n*** DELETE QUEUE ***\n";
			DeleteQueue(queue);
			queue = initializeQueue();
			cout << "\nQueue Deleted" << endl;
			break;

		case 6:
			cout << "\n Exiting..." << endl;
			exit(EXIT_SUCCESS);

		default: 
			cout << "Invalid Entry... Try Again" << endl;
			cin.clear();
			cin.ignore(150, '\n');
			break;
		}
		 


	}
	return 0;
}