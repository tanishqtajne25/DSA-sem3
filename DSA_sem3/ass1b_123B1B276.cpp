//123B1B276
//ass1b
// b. Arrange list of students alphabetically using shell sort 
#include <iostream>
using namespace std;

class Student{
    public:
    int roll;
    string name;
    float cgpa;

    // Function to input the student data
    void read(){
        cout << "Enter the name of student: ";
        cin >> name;
        cout << "Enter the roll number of student: ";
        cin >> roll;
        cout << "Enter the CGPA of student: ";
        cin >> cgpa;
    }

    // Function to display the student data
    void display(){
        cout << "\nName of the student is: " << name;
        cout << "\nRoll number is: " << roll;
        cout << "\nCGPA of student is: " << cgpa;
    }
};

// Shell sort function to sort students by their names
void shellSort(Student s[], int n){
    int interval = n / 2;
    while(interval >= 1){
        for(int i = interval; i < n; i++){
            Student temp = s[i];
            int j = i - interval;

            // Compare the names lexicographically using '>' operator
            for(; j >= 0; j -= interval){
                if(s[j].name > temp.name){
                    s[j + interval] = s[j];
                }
                else break;
            }
            s[j + interval] = temp;
        }
        interval /= 2;
    }
}

int main(){
    Student s[10];  // Array to store up to 10 students
    int n;

    // Input the number of students
    cout << "Enter the number of students: ";
    cin >> n;

    // Read the data for each student
    for(int i = 0; i < n; i++){
        s[i].read();
    }

    // Sort the students by their names using shell sort
    shellSort(s, n);

    // Display the sorted student information
    cout << "\nSorted list of students by name:\n";
    for(int i = 0; i < n; i++){
        s[i].display();
    }

    return 0;
}
