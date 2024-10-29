//Assignment No - 9 : b] Implement a checkout system for a supermarket to efficiently manage customer queues during peak hours. The system should support the following operations using a circular queue data structure: a. Customer arrival b. Customer checkout c. Close Checkout Counter d. View customer.
#include <iostream>
using namespace std;

#define SIZE 5

class Customer {
public:
    string name;
    Customer() {}
    Customer(string n) {
        name = n;
    }
};

class CircularQueue {
private:
    Customer queue[SIZE]; // declaring the queue array
    int front, rear;
    
public:
    CircularQueue() {
        front = rear = -1;
    }

    bool isFull() {
        return (rear + 1) % SIZE == front; // Check if the queue is full
    }

    bool isEmpty() {
        return front == -1; // The queue is empty if front is -1.
    }

    void enqueue(Customer customer) {
        if (isFull()) { // Function to check if queue is full
            cout << "Queue is full! Cannot add customer: " << customer.name << endl;
            return;
        }
        if (isEmpty()) {
            front = rear = 0;
        } else {
            rear = (rear + 1) % SIZE;
        }
        queue[rear] = customer;
        cout << "Customer " << customer.name << " added to the queue." << endl;
    }

    Customer dequeue() { // Function to delete
        if (isEmpty()) {
            cout << "Queue is empty! No customers to checkout." << endl;
            return Customer();
        }
        Customer customer = queue[front];
        if (front == rear) { // Queue has only one element
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
        cout << "Customer " << customer.name << " has checked out." << endl;
        return customer;
    }

    void closeCheckout() { // Function to checkout
        front = rear = -1;
        cout << "Checkout counter closed." << endl;
    }

    void viewCustomers() {
        if (isEmpty()) {
            cout << "No customers in the queue." << endl;
            return;
        }
        cout << "Current customer at the front of the queue: " << peek().name << endl;
        cout << endl;
    }

    Customer peek() { // Function to get the current customer at the front
        if (isEmpty()) {
            cout << "Queue is empty! No customers at the front." << endl;
            return Customer();
        }
        return queue[front];
    }
};

int main() {
    CircularQueue queue; // Use the default size
    int choice;
    string name;
    cout << "\nCheckout System Menu:\n";
    cout << "1. Customer Arrival\n";
    cout << "2. Customer Checkout\n";
    cout << "3. Close Checkout Counter\n";
    cout << "4. View Customers\n";
    cout << "5. Exit\n";
    
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter customer name: ";
                cin >> ws; // Clear leading whitespace
                cin >> name;
                queue.enqueue(Customer(name));
                break;
            case 2:
                queue.dequeue();
                break;
            case 3:
                queue.closeCheckout();
                break;
            case 4:
                queue.viewCustomers();
                break;
            case 5:
                cout << "Exiting the system." << endl;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 5);
    
    return 0;
}
