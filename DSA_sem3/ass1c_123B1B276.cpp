//123B1B276
//ass1c
//c. Arrange list of students to find out first ten toppers from a class using Radix sort.
#include <iostream>
using namespace std;

class Student{
    
    int rno;
    string name;
    float sgpa;  // CGPA in float

public:
    // Function to input student details
    void read(){
        cout << "Enter roll no: ";
        cin >> rno;
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter CGPA: ";
        cin >> sgpa;
    }

    // Function to display student details
    void display(){
        cout << "Roll no: " << rno << endl;
        cout << "Name: " << name << endl;
        cout << "CGPA: " << sgpa << endl;
    }

    // Getter for CGPA as an integer (scaled)
    int getIntCgpa() {
        return (int)(sgpa * 1000); // Scale CGPA to an integer by multiplying by 1000
    }

    // Getter for actual CGPA (for display purposes)
    float getCgpa() {
        return sgpa;
    }

    // Friend functions for sorting
    friend Student getMax(Student s[], int n);
    friend void countsort(Student s[], int n, int exp);
    friend void radixsort(Student s[], int n);
};

// Function to get the student with the maximum CGPA (scaled)
Student getMax(Student s[], int n) {
    Student mx = s[0];
    for (int i = 1; i < n; i++) {
        if (s[i].getIntCgpa() > mx.getIntCgpa()) {
            mx = s[i];
        }
    }
    return mx;
}

// Count sort for a specific digit (exp) on the scaled CGPA
void countsort(Student s[], int n, int exp) {
    Student output[n];  // Output array
    int count[10] = {0};  // Count array initialized to 0

    // Store count of occurrences
    for (int i = 0; i < n; i++) {
        int index = (s[i].getIntCgpa() / exp) % 10;
        count[index]++;
    }

    // Change count[i] so that it contains the actual position of this digit in output[]
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (s[i].getIntCgpa() / exp) % 10;
        output[count[index] - 1] = s[i];
        count[index]--;
    }

    // Copy the output array to s[], so that s[] contains sorted numbers
    for (int i = 0; i < n; i++) {
        s[i] = output[i];
    }
}

// Radix sort to sort students based on CGPA (scaled)
void radixsort(Student s[], int n) {
    // Find the student with the maximum CGPA (scaled)
    Student mx = getMax(s, n);
    int m = mx.getIntCgpa();

    // Do counting sort for every digit. The exp is 1, 10, 100, etc.
    for (int exp = 1; m / exp > 0; exp *= 10) {
        countsort(s, n, exp);
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    Student s[100];  // Assuming we can handle up to 100 students

    // Reading student details
    for (int i = 0; i < n; i++) {
        s[i].read();
    }
    cout << endl;

    // Sorting students based on CGPA using radix sort
    radixsort(s, n);

    // Display the top 10 students (or fewer if there are less than 10)
    int count = min(n, 10);
    cout << "\nTop " << count << " students based on CGPA:\n";
    for (int i = 0; i < count; i++) {
        s[i].display();
        cout << endl;
    }

    return 0;
}
