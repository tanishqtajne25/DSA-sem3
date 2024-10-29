//123B1B276
//2.B Arrange list of Employee alphabetically using Merge Sort.
#include<iostream>
using namespace std;

class employee{
  int id;               
  string name;          
  int salary;           
  public:
  // Function to read employee details
  void read(){
      cout<<"Enter ID : ";
      cin>>id;
      cout<<"Enter name : ";
      cin>>name;
      cout<<"Enter salary : ";
      cin>>salary;
  }

  // Function to display employee details
  void display(){
      cout<<"ID of employee is : "<<id<<endl;
      cout<<"Name of employee is : "<<name<<endl;
      cout<<"Salary of Employee is : "<<salary<<endl;
  }

  // Declaring mergeSort and merge as friend functions to access private members
  friend void mergeSort(employee e[],int low,int high);
  friend void merge(employee e[],int low,int mid,int high);
};

// Recursive function to sort the array using Merge Sort algorithm
void mergeSort(employee e[],int low,int high){
    if(low>=high){   // Base case: when only one element is left
        return;
    }
    int mid=(low+high)/2;  // Finding the middle index
    mergeSort(e,low,mid);  // Sorting the left half
    mergeSort(e,mid+1,high);  // Sorting the right half
    merge(e,low,mid,high);  // Merging the two sorted halves
}

// Function to merge two sorted sub-arrays
void merge(employee e[],int low,int mid,int high){
    employee temp[20];  // Temporary array to hold the merged result
    int left=low;       // Pointer for the left sub-array
    int right=mid+1;    // Pointer for the right sub-array
    int i = 0;          // Index for the temp array
    
    // Merge the two sub-arrays in sorted order
    while(left<=mid && right<=high){
        if(e[left].name <= e[right].name){  // Compare based on employee name
            temp[i]=e[left];
            left++;
        }
        else{
            temp[i] = e[right];
            right++;
        }
        i++;
    }

    // Copy remaining elements of the left sub-array, if any
    while(left<=mid){
        temp[i]=e[left];
        left++;
        i++;
    }

    // Copy remaining elements of the right sub-array, if any
    while(right<=high){
        temp[i]=e[right];
        right++;
        i++;
    }

    // Copy the merged array back to the original array
    for(int i=low;i<=high;i++){
        e[i]=temp[i-low];
    }
}

int main(){
    cout<<"Enter the number of Employees : ";
    int n;
    cin>>n;
    
    employee e[20];  // Array of employees
    
    for(int i=0;i<n;i++){
        e[i].read();
    }

    mergeSort(e,0,n-1);
    
    // Displaying the sorted list of employees
    cout<<"Sorted list is :"<<endl;
    for(int i=0;i<n;i++){
        e[i].display();
    }
    
    return 0;
}
