#include<iostream>
using namespace std;

// Define a template class named Undostack
template <typename T>
class Undostack {
    T* elements;    // Pointer to store elements of the stack
    int maxSize;    // Maximum size of the stack
    int topIndex;   // Index of the top element

    // Helper function to remove the oldest element in the stack
    void popOldest() {
        for (int i = 0; i < topIndex; i++) {
            elements[i] = elements[i + 1];  // Shift elements to remove the oldest
        }
        topIndex--;  // Decrease the top index
    }
public:
    // Constructor to initialize the stack
    Undostack() {
        maxSize = 100;          // Set maximum size to 100 (you can change this)
        elements = new T[maxSize];  // Dynamically allocate memory for elements
        topIndex = -1;           // Initialize the top index to -1 (empty stack)
    }

    // Function to push an element onto the stack
    void Push(const T& val) {
        if (topIndex == maxSize - 1) {
            popOldest();   // If the stack is full, remove the oldest element
        }
        else {
            int t = ++topIndex;  // Increment top index and store the value
            elements[t] = val;
        }
    }

    // Function to check if the stack is empty
    bool Isempty() {
        if (topIndex == -1) {
            return true;  // If top index is -1, the stack is empty
        }
        return false;  // Otherwise, the stack is not empty
    }

    // Function to get the current size of the stack
    int size() {
        return (topIndex + 1);  // Size is one more than the top index
    }

    // Function to pop (remove) the top element from the stack
    void pop() {
        if (!Isempty()) {
            topIndex--;  // If not empty, decrease the top index
        }
        else {
            cout << "Can't pop. Stack is empty." << endl;  // Print an error message if the stack is empty
        }
    }

    // Function to get the top element of the stack
    T top() {
        if (!Isempty()) {
            return elements[topIndex];  // If not empty, return the top element
        }
        else {
            cout << "The stack is empty." << endl;  // Print an error message if the stack is empty
        }
    }
};

int main() {
    // Create an instance of the Undostack class with integer type
    Undostack<int> undoStack;

    // Push elements from 1 to 101 into the stack
    for (int i = 1; i <= 101; i++) {
        undoStack.Push(i);
    }
    undoStack.pop();
    undoStack.pop();

    // Print the top element of the stack
    cout << "Top element: " << (undoStack.top()) << endl;

    // Check if the stack is empty and print the result
    cout << "Is the stack empty? " << ((undoStack.Isempty()) ? "Yes" : "No") << endl;

    // Print the current size of the stack
    cout << "Stack size: " << (undoStack.size()) << endl;
}
