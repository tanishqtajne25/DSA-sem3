//123B1B276
//Assignment No - 7 : Implement a browser history management system using a stack data structure to track the user's browsing history. The system should support the following functionalities: a. Add visited page b. Navigate back c. View current page d. Check if history is empty or not Assume no upper bound on number of pages visited.
#include<iostream>
using namespace std;

class webP {
public:
	string name;  // Name of the website
	webP* next;   // Pointer to the next website in the stack

	webP() {
    	next = NULL;  // Initialize next to NULL
	}

	// Function to input the website name
	void read() {
    	cout << "Enter website name: ";
    	cin >> name;
	}

	// Function to display the website name
	void display() {
    	cout << "Website is " << name << endl;
	}
};

class BrowserH {
public:
	webP* top;  // Pointer to the top of the stack (most recent website)

	BrowserH() {
    	top = NULL;  // Initialize top to NULL (empty stack)
	}

	bool isEmpty() {
    	return top == NULL;
	}

	void push() {
    	webP* new_name = new webP;  // Create a new website node
    	new_name->read();           // Read website name from user
    	new_name->next = top;       // Link the new website to the previous top
    	top = new_name;             // Update the top to the new website
	}

	void pop() {
    	if (this->isEmpty()) {
        	cout << "\nStack Underflow" << endl;  // If stack is empty, display an error
    	}
    	else {
        	webP* temp = top;     // Temporarily store the current top
        	top = top->next;      // Move the top pointer to the next website
        	delete temp;          // Delete the old top
    	}
	}

	string peek() {
    	if (!isEmpty()) {
        	return top->name;   // Return the name of the current website
    	}
    	else {
        	cout << "\nStack is empty\n";
        	return "";  // Return an empty string if the stack is empty
    	}
	}

	void displayH() {
    	webP* cn = top;  // Start from the top of the stack
    	if (isEmpty()) {
        	cout << "No Browsing history\n";  // If the stack is empty, display a message
        	return;
    	}
    	while (cn != NULL) {
        	cn->display();  // Display the website name
        	cn = cn->next;  // Move to the next website
    	}
	}
};

int main() {
	BrowserH h1;  
	int choice;   

	cout << "1. Add Website\n2. View Current Website\n3. Remove Website\n4. Display History\n5. Exit\n";
	do {
    	cout << "Please enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	h1.push(); 
            	break;
        	case 2:
            	cout << "Current website is: " << h1.peek() << endl;  
            	break;
        	case 3:
            	h1.pop();  
            	cout << "Website is deleted from browsing history\n";
            	break;
        	case 4:
            	cout << "Displaying browsing history:\n";
            	h1.displayH();  
            	break;
        	case 5:
            	cout << "Exiting...\n";  
            	break;
        	default:
            	cout << "Invalid choice\n";  
    	}
	} while (choice != 5);  

	return 0;
}
