#include <iostream>
using namespace std;

class Stack {
private:
    char a[100]; // Array to store stack elements
    int top;     // Index of the top element

public:
    // Constructor
    Stack() {
        top = -1; // Initialize stack as empty
    }

    // Push operation
    void push(char x) {
        if (top >= 99) {
            cout << "Stack Overflow\n"; // Print error if stack is full
            return; // Exit the function if the stack is full
        }
        a[++top] = x; // Increment top and push the element
    }
      
    // Pop operation
    char pop() {
        if (top == -1) {
            cout << "Stack Underflow\n"; // Print error if stack is empty
            return '\0'; // Return null character
        }
        return a[top--]; // Return top element and decrement top
    }

    // Peek operation
    char peek() {
        if (top == -1) {
            return '\0'; // Return null if stack is empty
        }
        return a[top]; // Return the top element
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1; // Return true if stack is empty
    }

    // Operator precedence
    int prec(char c) {
        if (c == '^')
            return 3;
        else if (c == '/' || c == '*')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1; // For non-operators
    }
    
    // Function to return associativity of operators
    char associativity(char c) {
        if (c == '^')
            return 'R'; // Right associative
        return 'L'; // Left associative
    }
};

// Helper function to reverse a string without using the <algorithm> library
void reverseString(string &s) {
    int n = s.length();
    for (int i = 0; i < n / 2; i++) {
        swap(s[i], s[n - i - 1]);
    }
}

// Function to convert infix to postfix
void infixToPostfix(string s) {
    Stack st; // Create a stack for operators
    string result; // To store the resulting postfix expression

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, add it to the result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } 
        // If the character is '(', push it to the stack
        else if (c == '(') {
            st.push('(');
        } 
        // If the character is ')'
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop(); // Pop from stack to result
            }
            st.pop(); // Pop the '(' from the stack
        } 
        // If the character is an operator
        else {
            while (!st.isEmpty() && (st.peek() != '(' && (st.prec(c) < st.prec(st.peek()) ||
                   (st.prec(c) == st.prec(st.peek()) && st.associativity(c) == 'L')))) {
                result += st.pop(); // Pop operators from stack to result
            }
            st.push(c); // Push the current operator onto the stack
        }
    }
    // Pop all the remaining elements from the stack
    while (!st.isEmpty()) {
        result += st.pop();
    }

    cout << "Postfix: " << result << endl; // Print the postfix expression
}

// Function to convert infix to prefix
void infixToPrefix(string s) {
    // Reverse the infix expression manually
    reverseString(s);

    // Replace '(' with ')' and vice versa
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            s[i] = ')';
        } else if (s[i] == ')') {
            s[i] = '(';
        }
    }

    // Convert the modified infix expression to postfix
    Stack st;
    string result;
    
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        // If the character is an operand, add it to the result
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        } 
        // If the character is '(', push it to the stack
        else if (c == '(') {
            st.push('(');
        } 
        // If the character is ')'
        else if (c == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                result += st.pop(); // Pop from stack to result
            }
            st.pop(); // Pop the '(' from the stack
        } 
        // If the character is an operator
        else {
            while (!st.isEmpty() && (st.peek() != '(' && (st.prec(c) < st.prec(st.peek()) ||
                   (st.prec(c) == st.prec(st.peek()) && st.associativity(c) == 'L')))) {
                result += st.pop(); // Pop operators from stack to result
            }
            st.push(c); // Push the current operator onto the stack
        }
    }

    // Pop all the remaining elements from the stack
    while (!st.isEmpty()) {
        result += st.pop();
    }

    // Reverse the postfix expression manually to get the prefix expression
    reverseString(result);

    cout << "Prefix: " << result << endl; // Print the prefix expression
}

int main() {
    int choice;
    string exp;
    do {
        cout << "Enter an infix expression (or type 'exit' to quit): ";
        cin >> exp;

        // Check for exit condition
        if (exp == "exit") {
            break;
        }

        // Convert infix to postfix
        infixToPostfix(exp);

        // Convert infix to prefix
        infixToPrefix(exp);

        cout << "Do you want to enter another expression? (1: Yes, 0: No): ";
        cin >> choice;
    } while (choice == 1);

    return 0; 
}
