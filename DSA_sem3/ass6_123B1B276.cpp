//123B1B276
//Assignment No - 6 : Consider two polynomial expressions of any degree. Design solution to perform addition of these two polynomials with suitable data structure and display results.
#include <iostream>
using namespace std;

class Node {
public:
	int coefficient;
	int exponent;
	Node* next;

	Node(int c, int e) {
    	coefficient = c;
    	exponent = e;
	}
};

class Polynomial {
public:
	Node* head;

	Polynomial() {
    	head = NULL;
	}
    
	// Function to add a term in the polynomial
	void addTerm(int coefficient, int exponent) {
    	if (coefficient == 0) return; // No need to add zero coefficient
    	Node* newNode = new Node(coefficient, exponent);
   	 
    	// If list is empty or the term should be placed at the beginning
    	if (!head || head->exponent < exponent) {
        	newNode->next = head;
        	head = newNode;
        	return;
    	}
   	 
    	Node* current = head;
    	Node* previous = nullptr;

    	// Traverse to the correct position for the term
    	while (current && current->exponent > exponent) {
        	previous = current;
        	current = current->next;
    	}
   	 
    	// If a term with the same exponent is found, add the coefficients
    	if (current && current->exponent == exponent) {
        	current->coefficient += coefficient;
        	// If the resulting coefficient is 0, remove the node
        	if (current->coefficient == 0) {
            	if (previous) previous->next = current->next;
            	else head = current->next;
            	delete current;
        	}
        	return;
    	}
   	 
    	// Insert the new term
    	newNode->next = current;
    	if (previous) previous->next = newNode;
    	else head = newNode;
	}

	// Function to display the polynomial
	void display() {
    	Node* current = head;
    	if (!current) {
        	cout << "0"; // Display 0 if polynomial is empty
        	return;
    	}
   	 
    	bool first = true;
    	while (current) {
        	if (!first) {
            	cout << (current->coefficient > 0 ? " + " : " ");
        	}
        	cout << current->coefficient << "x^" << current->exponent;
        	current = current->next;
        	first = false;
    	}
    	cout << endl;
	}
    
	// Function to input polynomial terms from the user
	void input() {
    	int n;
    	cout << "Enter the number of terms in the polynomial: ";
    	cin >> n;

    	for (int i = 0; i < n; i++) {
        	int coefficient, exponent;
        	cout << "Enter coefficient and exponent for term " << (i + 1) << ": ";
        	cin >> coefficient >> exponent;
        	addTerm(coefficient, exponent);
    	}
	}
};

// Function to add two polynomials
Polynomial addPolynomials(Polynomial& p1, Polynomial& p2) {
	Polynomial result;
    
	Node* ptr1 = p1.head;
	Node* ptr2 = p2.head;
	// Traverse both linked lists
	while (ptr1 || ptr2) {
    	if (!ptr1) {
        	result.addTerm(ptr2->coefficient, ptr2->exponent);
        	ptr2 = ptr2->next;
    	}
    	else if (!ptr2) {
        	result.addTerm(ptr1->coefficient, ptr1->exponent);
        	ptr1 = ptr1->next;
    	}
    	else if (ptr1->exponent > ptr2->exponent) {
        	result.addTerm(ptr1->coefficient, ptr1->exponent);
        	ptr1 = ptr1->next;
    	}
    	else if (ptr1->exponent < ptr2->exponent) {
        	result.addTerm(ptr2->coefficient, ptr2->exponent);
        	ptr2 = ptr2->next;
    	}
    	else {
        	result.addTerm(ptr1->coefficient + ptr2->coefficient, ptr1->exponent);
        	ptr1 = ptr1->next;
        	ptr2 = ptr2->next;
    	}
	}
    
	return result;
}

int main() {
	Polynomial p1, p2, result;
	int choice;
	bool p1Input = false, p2Input = false;  // Flags to check if polynomials are inputted

	do {
    	cout << "Menu:\n";
    	cout << "1. Input Polynomial 1\n";
    	cout << "2. Input Polynomial 2\n";
    	cout << "3. Display Polynomial 1\n";
    	cout << "4. Display Polynomial 2\n";
    	cout << "5. Add Polynomials and Display Result\n";
    	cout << "6. Exit\n";
    	cout << "Enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	cout << "Input for Polynomial 1:" << endl;
            	p1.input();
            	p1Input = true;  // Mark Polynomial 1 as inputted
            	break;

        	case 2:
            	cout << "Input for Polynomial 2:" << endl;
            	p2.input();
            	p2Input = true;  // Mark Polynomial 2 as inputted
            	break;

        	case 3:
            	if (p1Input) {
                	cout << "Polynomial 1: ";
                	p1.display();
            	} else {
                	cout << "Polynomial 1 is not yet inputted." << endl;
            	}
            	break;

        	case 4:
            	if (p2Input) {
                	cout << "Polynomial 2: ";
                	p2.display();
            	} else {
                	cout << "Polynomial 2 is not yet inputted." << endl;
            	}
            	break;

        	case 5:
            	if (p1Input && p2Input) {
                	result = addPolynomials(p1, p2);
                	cout << "Sum of Polynomials: ";
                	result.display();
            	} else {
                	cout << "Please input both Polynomial 1 and Polynomial 2 first." << endl;
            	}
            	break;

        	case 6:
            	cout << "Exiting the program." << endl;
            	break;

        	default:
            	cout << "Invalid choice! Please try again." << endl;
    	}
	} while (choice != 6);

	return 0;
}
