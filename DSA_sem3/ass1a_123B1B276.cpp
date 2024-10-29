//123B1B276
//ass1a
//a. Design a roll call list, arrange list of students according to roll numbers in ascending order using Insertion Sort
#include <iostream>
using namespace std;

// Class to represent a student with private attributes
class Student{
   private:
   int roll;
   string name;
   float cgpa;

   public:
   // Function to input the student data
   void read(){
       cout<<"Enter the name of student : ";
       cin>>name;
       cout<<"Enter the roll number of student : ";
       cin>>roll;
       cout<<"Enter the SGPA of student : ";
       cin>>cgpa;
   }

   // Function to display the student data
   void display(){
       cout<<"\nName of the student is : "<<name;
       cout<<"\nRoll number is : "<<roll;
       cout<<"\nSGPA of student is : "<<cgpa;
   }

   // Getter function to access roll number (as roll is private)
   int getRoll(){
       return roll;
   }
};

// Function to perform insertion sort based on roll numbers
void insertionsort(Student s[], int n){
    for (int i = 1; i < n; i++) {
        Student x = s[i];  // Temporarily store the current student
        int j = i - 1;

        // Use getter function getRoll() to access roll number
        while(j >= 0 && s[j].getRoll() > x.getRoll()) {
            s[j+1] = s[j];
            j--;
        }
        s[j+1] = x;  // Place the student in the correct position
    }
}

int main() {
    Student s[15];  // Array to store up to 10 students
    int n;

    // Input the number of students
    cout<<"Enter the number of students: ";
    cin>>n;

    // Read the data for each student
    for(int i=0; i<n; i++){
        s[i].read();
    }

    // Sort the students by their roll numbers
    insertionsort(s, n);

    // Display the sorted student information
    for(int i = 0; i<n; i++){
        s[i].display();
    }

    return 0;
}
