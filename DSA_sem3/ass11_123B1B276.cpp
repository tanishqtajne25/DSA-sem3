//Assignment No - 11 : Consider an employee database of N employees. Make use of a hash table implementation to quickly look up the employer's id number.
#include <iostream>
using namespace std;
#define SIZE 10

class emp {
public:
	int id;
	string name;
	int flag;

	emp(){
    	id = 0;
    	flag = 0;
    	name = "";
	}

	void read() {
    	cout << "Enter employee ID: ";
    	cin >> id;
    	cout << "Enter employee name: ";
    	cin >> name;
    	flag = 1;  // Mark as occupied
	}

	void display() {
    	cout << "Employee Name: " << name << endl;
    	cout << "Employee ID: " << id << endl;
	}
};

class empM {
public:
	emp HT[SIZE];
	int hashFunction(int id) {
    	return id % SIZE;
	}

	void insert() {
    	for (int i = 0; i < SIZE; i++) {
        	emp newEmp;
        	newEmp.read();
        	int index = hashFunction(newEmp.id);
        	int originalIndex = index;

        	// Linear probing to handle collisions
        	while (HT[index].flag == 1) {
            	index = (index + 1) % SIZE; // Move to the next index
            	if (index == originalIndex) {
                	cout << "Hash table is full. Cannot insert employee." << endl;
                	return;
            	}
        	}

        	HT[index] = newEmp; // Insert the new employee
    	}
	}
	emp search(int id) {
    	int index = hashFunction(id);
    	int originalIndex = index;

    	// Linear probing to find the employee
    	while (HT[index].flag == 1) {
        	if (HT[index].id == id) {
            	return HT[index]; // Return the found employee
        	}
        	index = (index + 1) % SIZE; // Move to the next index
        	if (index == originalIndex) {
            	break;
        	}
    	}
    	return emp();
	}
};

int main() {
    
	empM m1;
	m1.insert();
	int choice;
	cout<<"Enter 1 for searching\n0 for exiting";
	do{
	cout<<"enter choice";
	cin>>choice;
    	switch(choice){
        	case 1:
        	int searchId;
        	cout << "Enter employee ID to search: ";
        	cin >> searchId;

        	emp foundEmp = m1.search(searchId);
        	if (foundEmp.flag == 1) {
        	foundEmp.display();
        	}else{
        	cout << "Employee not found." << endl;
        	}
        	break;
    	}
	}while(choice!=0);
    	return 0;
}