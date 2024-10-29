//Assignment No - 10 : Implement a job scheduling system for a manufacturing plant using a double-ended queue. The system needs to efficiently manage the processing of jobs on various machines throughout the plant. Each job has a Job_priority. The system should support the following operations: a. Add Job b. Remove Job c. Display Job d. Search Job
#include <iostream>
#define MAX 5
using namespace std;
// Class to represent a Job with ID and priority
class Job {
public:
    int id;
    int priority;
     // Default constructor
    Job(){
        id = -1;
        priority = -1;
    }
    // Parameterized constructor
    Job(int i,int p){
        id = i;
        priority = p;
    }
};
class DeQueue {
    Job arr[MAX]; // Array to store jobs in the queue
    int front, rear; // Front and rear pointers
public:
    DeQueue() {
        front = rear = -1; // Initialize front and rear to -1
    }
    // Check if the queue is empty
    bool isEmpty() {
        return (front == -1);
    }
    // Check if the queue is full
    bool isFull() {
        return (front == (rear + 1) % MAX);
    }
    // Insert a job at the rear of the queue
    void insertAtRear(Job job) {
        if (isFull()) { // Check if queue is full
            cout << "Queue is full! Cannot add job at the rear.\n";
            return;
        }
        rear = (rear + 1) % MAX; // Update rear pointer
        arr[rear] = job; // Insert job at rear
        if (front == -1) { // If queue was empty, update front
            front = 0;
        }
    }
    // Insert a job at the front of the queue
    void insertAtFront(Job job) {
        if (isFull()) { // Check if queue is full
            cout << "Queue is full! Cannot add job at the front.\n";
            return;
        }
        if (front == -1) { // If queue is empty
            front = rear = 0;
        } else if (front == 0) {
            front = MAX - 1; // Wrap around front to end of array
        } else {
            front = front - 1;
        }
        arr[front] = job; // Insert job at front
    }
    // Delete a job from the rear of the queue
    Job deleteFromRear() {
        if (isEmpty()) { // Check if queue is empty
            cout << "Queue is empty! Cannot delete job from rear.\n";
            return Job();
        }
        Job returnValue = arr[rear]; // Store job to return
        if (rear == front) { // If only one element is left
            front = rear = -1;
        } else if (rear == 0) {
            rear = MAX - 1; // Wrap rear to end of array
        } else {
            rear = rear - 1;
        }
        return returnValue; // Return deleted job
    }
    // Delete a job from the front of the queue
    Job deleteFromFront() {
        if (isEmpty()) { // Check if queue is empty
            cout << "Queue is empty! Cannot delete job from front.\n";
            return Job();
        }
        Job returnValue = arr[front]; // Store job to return
        if (rear == front) { // If only one element is left
            front = rear = -1;
        } else {
            front = (front + 1) % MAX; // Move front pointer forward
        }
        return returnValue; // Return deleted job
    }
    // Display all jobs in the queue
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        cout << "Jobs in the queue:\n";
        int i = front;
        while (true) { // Loop to display jobs from front to rear
            cout << "Job ID: " << arr[i].id << ", Priority: " << arr[i].priority << "\n";
            if (i == rear) break;
            i = (i + 1) % MAX; // Move to next element
        }
    }
    // Search for a job by its priority
    void searchJob(int priority) {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        int i = front;
        bool found = false;
        while (true) {
            if (arr[i].priority == priority) { // If job with priority found
                cout << "Job found! ID: " << arr[i].id << ", Priority: " << arr[i].priority << "\n";
                found = true;
                break;
            }
            if (i == rear) break;
            i = (i + 1) % MAX; // Move to next element
        }
        if (!found) { // If job not found
            cout << "Job with priority " << priority << " not found.\n";
        }
    }
};
int main() {
    DeQueue dq; // Create a DeQueue object
    int choice, id, priority;
    do {
        cout << "\n--- Job Scheduling System ---\n";
        cout << "1. Add Job at Rear\n";
        cout << "2. Add Job at Front\n";
        cout << "3. Remove Job from Rear\n";
        cout << "4. Remove Job from Front\n";
        cout << "5. Display Jobs\n";
        cout << "6. Search Job by Priority\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Enter Job ID and Priority: ";
                cin >> id >> priority;
                dq.insertAtRear(Job(id, priority)); // Add job at rear
                break;
            case 2:
                cout << "Enter Job ID and Priority: ";
                cin >> id >> priority;
                dq.insertAtFront(Job(id, priority)); // Add job at front
                break;
            case 3:
                dq.deleteFromRear(); // Remove job from rear
                break;
            case 4:
                dq.deleteFromFront(); // Remove job from front
                break;
            case 5:
                dq.display(); // Display all jobs
                break;
            case 6:
                cout << "Enter Priority to search: ";
                cin >> priority;
                dq.searchJob(priority); // Search for a job by priority
                break;
            case 0:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    } while (choice != 0); // Repeat until user chooses to exit
}
