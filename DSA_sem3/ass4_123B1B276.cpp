#include<iostream>
using namespace std;

class text {
  public:
    string s;      // Holds the actual text content
    text* next;    // Pointer to the next node
    text* prev;    // Pointer to the previous node
    
    text() {
        next = NULL;
        prev = NULL;
    }

    void read() {
        cout << "Enter text: ";
        cin >> s;
    }

    void display() {
        cout << s;
    }
};

class TextEditor {
  public:
    text* head;    // Pointer to the first node in the list
    text* tail;    // Pointer to the last node in the list

    // Constructor to initialize the text editor with an empty list
    TextEditor() {
        head = NULL;
        tail = NULL;
    }

    // Function to insert text at the beginning of the list
    void insertAtBeg() {
        text* nn = new text;  // Creating a new node
        nn->read();  // Reading text input from the user
        if (head == NULL) {  // If the list is empty
            head = nn;
            tail = nn;  // Both head and tail point to the new node
        } else {
            nn->next = head;  // Link the new node to the current head
            head->prev = nn;  // Set the previous pointer of the current head
            head = nn;  // Make the new node the head
        }
    }

    // Function to insert text at the end of the list
    void insert_end() {
        text* nn = new text;  // Creating a new node
        nn->read();  // Reading text input from the user
        if (head == NULL) {  // If the list is empty
            head = nn;
            tail = nn;  // Both head and tail point to the new node
        } else {
            tail->next = nn;  // Link the current tail to the new node
            nn->prev = tail;  // Set the previous pointer of the new node
            tail = nn;  // Make the new node the tail
        }
    }

    // Function to display the list of text nodes in forward order
    void displayF() {
        cout << "Display in forward" << endl;
        text* cn;
        for (cn = head; cn != NULL; cn = cn->next) {  // Traverse the list from head to tail
            cn->display();
            cout << " ";
        }
        cout << endl;
    }

    // Function to delete the first node from the list
    void delete_beg() {
        if (head == NULL) {  // Check if the list is empty
            cout << "List is empty" << endl;
            return;
        }
        text* temp = head;  // Store the current head
        if (head->next == NULL) {  // If there is only one node
            head = NULL;
            tail = NULL;  // List becomes empty
        } else {
            head = head->next;  // Move head to the next node
            head->prev = NULL;  // Remove the link to the old head
        }
        delete temp;  // Delete the old head node
    }

    // Function to display the list of text nodes in reverse order
    void reverse() {
        if (head == NULL) {  // Check if the list is empty
            cout << "List is empty" << endl;
            return;
        }
        cout << "Display in reverse" << endl;
        text* cn = head;
        while (cn->next != NULL) {  // Traverse to the end of the list
            cn = cn->next;
        }
        while (cn != NULL) {  // Display nodes in reverse order
            cn->display();
            cout << " ";
            cn = cn->prev;
        }
        cout << endl;
    }

    // Function to delete a node at a specific position
    void deletePos() {
        if (head == NULL) {  // Check if the list is empty
            cout << "List is empty, nothing to delete." << endl;
            return;
        }

        int pos;
        cout << "Enter Position: ";
        cin >> pos;
        text* temp = head;
        int currentPos = 1;

        while (temp != NULL && currentPos < pos) {  // Traverse to the position
            temp = temp->next;
            currentPos++;
        }
        if (temp == NULL) {  // If the position is out of range
            cout << "Position out of range" << endl;
            return;
        }
        if (temp->prev != NULL) {
            temp->prev->next = temp->next;  // Adjust links for previous node
        } else {
            head = temp->next;  // Deleting the first node
        }

        if (temp->next != NULL) {
            temp->next->prev = temp->prev;  // Adjust links for the next node
        } else {
            tail = temp->prev;  // Deleting the last node
        }
        delete temp;  // Delete the node at the specified position
    }

    // Function to search for text in the list
    void search() {
        string key;
        cout << "Enter text to be searched: ";
        cin >> key; 
        text* cn = head;
        int position = 1;
        while (cn != NULL) {  // Traverse through the list
            if (cn->s == key) {  // Check if the text matches
                cout << "The text is found at position " << position << endl;
                return;
            }
            cn = cn->next;
            position++;
        }
        cout << "Text not found" << endl;  // Text not found in the list
    }

};

int main() {
    TextEditor t;
    int c;
    cout << "Enter 1 for insert at beginning \n"
         << "Enter 2 for inserting at end \n"
         << "Enter 3 for deleting from beginning \n"
         << "Enter 4 for deleting at any position\n"
         << "Enter 5 for forward printing \n"
         << "Enter 6 for reverse printing \n"
         << "Enter 7 to search\n"
         << "Enter 8 to exit\n";

    do {
        cout << "Enter choice: ";
        cin >> c;
        switch (c) {
            case 1:
                t.insertAtBeg();
                break;
            case 2:
                t.insert_end();
                break;
            case 3:
                t.delete_beg();
                break;
            case 4:
                t.deletePos();
                break;
            case 5:
                t.displayF(); 
                break;
            case 6:
                t.reverse(); 
                break;
            case 7:
                t.search();
                break;
            case 8:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice, please enter again." << endl;
        }
    } while (c != 8);

    return 0;
}
