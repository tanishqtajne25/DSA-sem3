//123B1B276
//Assignment No - 5 : Implement a navigation system for a delivery service using a circular linked list to represent routes. The navigation system should support the following functionalities: a. Add route b. Remove route c. Display route.
#include <iostream>
#include <string>
using namespace std;

// Class representing a Route with source, destination, distance, and a pointer to the next route
class Route {
public:
	string source;       // Starting point of the route
	string destination;  // Ending point of the route
	float distance;      // Distance between source and destination
	Route* next;         // Pointer to the next Route in the circular linked list

	Route() {            // Constructor initializes the next pointer to NULL
    	next = NULL;
	}

	// Function to read route details from the user
	void read() {
    	cout << "Enter source: ";
    	cin >> source;
    	cout << "Enter destination: ";
    	cin >> destination;
    	cout << "Enter distance: ";
    	cin >> distance;
	}

	// Function to display the details of the route
	void display() {
    	cout << "Source: " << source << ", Destination: " << destination << ", Distance: " << distance << endl;
	}
};

// Class to handle navigation which contains a circular linked list of Route objects
class Navigation {
	Route* tail;  // Pointer to the last node (tail) of the circular linked list
public:
	Navigation() {  // Constructor initializes tail to NULL, indicating an empty list
    	tail = NULL;
	}
   
	// Function to insert a new route at the end of the list
	void insertAtEnd() {
    	Route* cn = new Route();  // Create a new route node
    	cn->read();  // Read route details from the user
    	if (tail == NULL) {  // If the list is empty
        	tail = cn;        // The new node becomes the only node, pointing to itself
        	cn->next = cn;
    	} else {  // Otherwise, insert the node after the current tail
        	cn->next = tail->next;  // The new node points to the first node
        	tail->next = cn;        // Tail's next points to the new node
        	tail = cn;              // Update the tail to the new node
    	}
	}
   
	// Function to insert a new route at the beginning of the list
	void insertAtHead() {
    	Route* cn = new Route();  // Create a new route node
    	cn->read();  // Read route details from the user
    	if (tail == NULL) {  // If the list is empty
        	tail = cn;        // The new node becomes the only node, pointing to itself
        	cn->next = cn;
    	} else {  // Otherwise, insert the node before the current head
        	cn->next = tail->next;  // The new node points to the first node
        	tail->next = cn;        // Tail's next points to the new node, making it the new head
    	}
	}
   
	// Function to display all routes in the list
	void displayRoutes() {
    	if (tail == NULL) {  // If the list is empty
        	cout << "No routes to display." << endl;
        	return;
    	}
    	Route* t = tail->next;  // Start from the head (tail->next)
    	do {  // Traverse the list and display each route
        	t->display();
        	t = t->next;
    	} while (t != tail->next);  // Continue until we reach the head again (circular list)
	}
   
	// Function to delete a route by source and destination
	void deleteRoute(string src, string dst) {
    	if (tail == nullptr) {  // If the list is empty
        	cout << "No routes to delete." << endl;
        	return;
    	}

    	Route* current = tail->next;  // Start from the head (tail->next)
    	Route* previous = tail;  // Keep track of the previous node during traversal

    	do {  // Traverse the list and search for the route to delete
        	if (current->source == src && current->destination == dst) {  // If the route is found
            	if (current == tail) {  // If the route to delete is the tail
                	if (tail->next == tail) {  // If there's only one node
                    	delete tail;  // Delete the tail
                    	tail = nullptr;  // Set the tail to NULL, list becomes empty
                	} else {  // If there are multiple nodes
                    	previous->next = current->next;  // Remove the tail from the list
                    	tail = previous;  // Update the tail to the previous node
                    	delete current;  // Delete the current node (old tail)
                	}
            	} else {  // If the route to delete is not the tail
                	previous->next = current->next;  // Remove the node from the list
                	if (current == tail->next) {  // If the route is the head
                    	tail->next = current->next;  // Update the head to the next node
                	}
                	delete current;  // Delete the node
            	}
            	cout << "Route from " << src << " to destination " << dst << " is deleted." << endl;
            	return;
        	}
        	previous = current;  // Move to the next node
        	current = current->next;
    	} while (current != tail->next);  // Continue until we reach the head again (circular list)

    	cout << "Route " << src << " with destination " << dst << " not found." << endl;  // Route not found
	}
};

int main() {
	Navigation Nav;  // Create a Navigation object
	int choice;
	cout << "1. Add route at the end\n"
     	<< "2. Add route at beginning\n"
     	<< "3. Display routes\n"
     	<< "4. Delete route\n"
     	<< "5. Exit.\n";
	do {
    	cout << "Enter your choice: ";
    	cin >> choice;

    	switch (choice) {
        	case 1:
            	Nav.insertAtEnd();  // Insert a route at the end
            	break;
        	case 2:
            	Nav.insertAtHead();  // Insert a route at the beginning
            	break;
        	case 3:
            	Nav.displayRoutes();  // Display all routes
            	break;
        	case 4: {  // Delete a route by source and destination
            	string src, dst;
            	cout << "Enter source of route to delete: ";
            	cin >> src;
            	cout << "Enter destination of that source: ";
            	cin >> dst;
            	Nav.deleteRoute(src, dst);
            	break;
        	}
        	case 5:
            	cout << "Exiting the program." << endl;
            	break;
        	default:
            	cout << "Invalid choice, please try again." << endl;
    	}
	} while (choice != 5);  // Continue the menu until the user chooses to exit

	return 0;
}
