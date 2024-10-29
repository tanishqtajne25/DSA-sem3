/*Assignment No - 9 :  a] Implement a restaurant waitlist system using the queue data structure. Restaurant waitlist provide following facility: a. Add Party to Waitlist b. Seat Party c. Display Waitlist*/
#include <iostream>
#include <string>
using namespace std;

#define SIZE 10 // Maximum size of the waitlist

class Party {
public:
	string name;
	int size; // Size of the party

	Party() {}
	Party(string n,int s){
    	name = n;
    	size = s;
	}
};

class Queue {
private:
	Party waitlist[SIZE]; // Array to hold the parties
	int front, rear;

public:
	Queue(){
    	front = -1;
    	rear = -1;
	}

	bool isFull() {
    	return (rear + 1) % SIZE == front; // Check if the queue is full
	}

	bool isEmpty() {
    	return front == -1; // Check if the queue is empty
	}

	void addParty(Party party) {
    	if (isFull()) {
        	cout << "Waitlist is full! Cannot add party: " << party.name << endl;
        	return;
    	}
    	if (isEmpty()) {
        	front = rear = 0; // First party added
    	} else {
        	rear = (rear + 1) % SIZE; // Circular increment
    	}
    	waitlist[rear] = party; // Add the party to the waitlist
    	cout << "Party " << party.name << " (Size: " << party.size << ") added to the waitlist." << endl;
	}

	Party seatParty() {
    	if (isEmpty()) {
        	cout << "Waitlist is empty! No parties to seat." << endl;
        	return Party();
    	}
    	Party party = waitlist[front]; // Get the party at the front
    	if (front == rear) { // If there's only one party
        	front = rear = -1; // Reset the queue
    	} else {
        	front = (front + 1) % SIZE; // Circular increment
    	}
    	cout << "Party " << party.name << " has been seated." << endl;
    	return party;
	}

	void displayWaitlist() {
    	if (isEmpty()) {
        	cout << "No parties in the waitlist." << endl;
        	return;
    	}
    	cout << "Current waitlist: " << endl;
    	int i = front;
    	while (true) {
        	cout << "Party Name: " << waitlist[i].name << ", Size: " << waitlist[i].size << endl;
        	if (i == rear) break;
        	i = (i + 1) % SIZE; // Circular increment
    	}
	}
};

int main() {
	Queue waitlist;
	int choice;
	string name;
	int size;

	do {
    	cout << "\nRestaurant Waitlist System Menu:\n";
    	cout << "1. Add Party to Waitlist\n";
    	cout << "2. Seat Party\n";
    	cout << "3. Display Waitlist\n";
    	cout << "4. Exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	cout << "Enter party name: ";
            	cin >> ws;
                cin>>name;
            	cout << "Enter party size: ";
            	cin >> size; // Get party size
            	waitlist.addParty(Party(name, size));
            	break;

        	case 2:
            	waitlist.seatParty();
            	break;

        	case 3:
            	waitlist.displayWaitlist();
            	break;

        	case 4:
            	cout << "Exiting the system." << endl;
            	break;

        	default:
            	cout << "Invalid choice! Please try again." << endl;
    	}
	} while (choice != 4);

	return 0;
}


