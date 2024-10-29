//123B1B276
//Assignment No - 2 : Consider Employee database of PCCOE (at least 20 records).
// Database contains different fields of every employee like EMP-ID, EMP-Name and EMP-Salary. a. Arrange list of employees according to EMP-ID in ascending order using Quick Sort

#include<iostream>
using namespace std;

class employee{
    int iemployeeID;    // Employee ID of the employee
    string sname;       // Name of the employee
    float salary;       // Salary of the employee

public:
    // Default constructor to initialize employee data
    employee(){
        iemployeeID = 0;
        sname = "";
        salary = 0.0;
    }
    
    // Parameterized constructor to initialize employee ID, name, and salary
    employee(int id, string name, float sal){
        iemployeeID = id;
        sname = name;
        salary = sal;
    }

    // Setter method to set employee ID, Name, and Salary
    void setEmployeeDetails(int empid, string name, float sal){
        iemployeeID = empid;
        sname = name;
        salary = sal;
    }

    // Getter method to get employee ID
    int getemployeeID(){
        return iemployeeID;
    }

    // Getter method to get employee name
    string getname(){
        return sname;
    }

    // Getter method to get employee salary
    float getsalary(){
        return salary;
    }
};

// Function to partition the array based on employee ID for quicksort
int partition(employee arr[], int left, int right){
    int i = left;
    int j = right;
    int pivot = arr[left].getemployeeID(); // Pivot is the first employee ID in the current partition

    // Loop to divide the array based on the pivot
    while(i < j){
        // Move the left pointer until a larger element is found
        while(arr[i].getemployeeID() <= pivot && i < right){
            i++;
        }
        // Move the right pointer until a smaller element is found
        while(arr[j].getemployeeID() > pivot){
            j--;
        }
        // Swap the left and right elements if pointers haven't crossed
        if(i < j){
            employee temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Swap the pivot element with the element at the right pointer position
    employee temp = arr[left];
    arr[left] = arr[j];
    arr[j] = temp;

    // Return the partition index
    return j;
}

// Recursive function to apply quicksort on the array
void qs(employee arr[], int left, int right){
    if(left < right){
        // Partition the array and get the pivot position
        int pivotP = partition(arr, left, right);

        // Recursively sort the elements before the pivot
        qs(arr, left, pivotP - 1);

        // Recursively sort the elements after the pivot
        qs(arr, pivotP + 1, right);
    }
}

int main(){
    int n;

    // Input: Number of employees
    cout << "Enter number of employees: ";
    cin >> n;

    employee arr[100]; // Assuming the max number of employees is 100

    // Input employee details from user
    for(int i = 0; i < n; i++){
        int empid;
        string name;
        float salary;
        
        // Take employee ID, Name, and Salary from user
        cout << "Enter Employee ID for employee " << (i+1) << ": ";
        cin >> empid;
        cout << "Enter Employee Name for employee " << (i+1) << ": ";
        cin.ignore();  // To ignore the newline character left by the previous input
        getline(cin, name);
        cout << "Enter Employee Salary for employee " << (i+1) << ": ";
        cin >> salary;

        // Store the employee data in the array
        arr[i].setEmployeeDetails(empid, name, salary);
    }

    // Apply quicksort on the employee array based on employee ID
    qs(arr, 0, n - 1);

    // Display the sorted list of employees by their IDs
    cout << "\nSorted Employee List by Employee ID:\n";
    for(int i = 0; i < n; i++){
        cout << "Employee ID: " << arr[i].getemployeeID() 
             << ", Name: " << arr[i].getname() 
             << ", Salary: " << arr[i].getsalary() << endl;
    }

    return 0;
}
