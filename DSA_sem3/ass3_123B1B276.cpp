//123B1B276
//Assignment No - 3 : Consider the playlist in a music player. Implement a playlist feature in music player application using singly linked list. Each song in the playlist is represented as a node in the linked list. Each node contains information about the song (such as title or artist or duration, etc.). The playlist should allow users to: a. Add songs b. Remove songs c. Display the entire playlist d. Play specific songs.
#include<iostream>
using namespace std;

class song {
public:
    string title;   
    string artist;  
    song* next;     

    song() {
        next = NULL;
    }

    // Function to read the details of the song from the user
    void read() {
        cout << "Enter title: ";
        cin >> title;
        cout << "Enter artist: ";
        cin >> artist;
    }

    // Function to display the details of the song
    void display() {
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
    }
};

class playlist {
public:
    song* head;  // Pointer to the first song in the playlist

    // Constructor to initialize an empty playlist
    playlist() {
        head = NULL;
    }

    // Function to display all songs in the playlist
    void displayP() {
        if (head == NULL) {  // Check if the playlist is empty
            cout << "Playlist is empty" << endl;
        } else {
            song* cn = head;  // Pointer to iterate through the playlist
            while (cn != NULL) {  // Traverse the playlist and display each song
                cn->display();
                cn = cn->next;
            }
        }
    }

    // Function to add a new song to the end of the playlist
    void addSong() {
        song* nn = new song;  // Create a new song node
        nn->read();  
        if (head == nullptr) {  
            head = nn;
        } else {
            song* cn = head;  // Traverse to the last song in the playlist
            while (cn->next != NULL) {
                cn = cn->next;
            }
            cn->next = nn;  // Add the new song at the end
        }
    }

    // Function to insert a song after a specific song by its title
    void insertP() {
        string afterTitle;
        cout << "Enter the title after which you want to insert the song: ";
        cin >> afterTitle;
        song* nn = new song;
        nn->read();  // Read new song details
        song* cn = head;  // Start searching from the head of the playlist
        while (cn != NULL && cn->title != afterTitle) {  // Search for the song with the given title
            cn = cn->next;
        }
        if (cn != NULL) {  // If the song is found, insert the new song after it
            nn->next = cn->next;
            cn->next = nn;
        } else {
            delete nn;  // If the song is not found, delete the new node
            cout << "Song with title " << afterTitle << " not found." << endl;
        }
    }

    // Function to insert a song at the beginning of the playlist
    void start() {
        song* nn = new song;  // Create a new song node
        nn->read();  // Read song details
        nn->next = head;  // Link the new song to the current head
        head = nn;  // Make the new song the head of the playlist
    }

    // Function to delete a song by its title
    void del() {
        string deleteS;
        cout << "Enter the title of the song to be deleted: ";
        cin >> deleteS;
        song* cn = head;

        // If the song to delete is at the head of the playlist
        if (cn != NULL && cn->title == deleteS) {
            head = cn->next;
            delete cn;
            cout << "Song deleted." << endl;
            return;
        }

        // Traverse the playlist to find the song to delete
        while (cn->next != nullptr && cn->next->title != deleteS) {
            cn = cn->next;
        }

        // If the song is found, delete it
        if (cn->next != nullptr) {
            song* toDelete = cn->next;
            cn->next = toDelete->next;
            delete toDelete;
            cout << "Song deleted." << endl;
        } else {
            cout << "Song with title " << deleteS << " not found." << endl;
        }
    }

    // Function to play a specific song based on its title
    void playSong() {
        string playTitle;
        cout << "Enter the title of the song you want to play: ";
        cin >> playTitle;

        song* cn = head;  // Start searching from the head of the playlist
        while (cn != NULL && cn->title != playTitle) {
            cn = cn->next;  // Traverse the playlist
        }

        if (cn != NULL) {  // If the song is found, display its details
            cout << "Now playing: " << endl;
            cn->display();
        } else {
            cout << "Song with title " << playTitle << " not found." << endl;
        }
    }
};

int main() {
    playlist p;
    int choice;

    do {
        cout << "1. Add Song\n2. Display Playlist\n3. Insert Song at Position\n4. Insert Song at Start\n5. Delete Song\n6. Play a Song\n7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                p.addSong();
                break;
            case 2:
                p.displayP();
                break;
            case 3:
                p.insertP();
                break;
            case 4:
                p.start();
                break;
            case 5:
                p.del();
                break;
            case 6:
                p.playSong();
                break;
            case 7:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 7);

    return 0;
}
