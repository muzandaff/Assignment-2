#include <iostream>
#include "Stack.h"

using namespace std;

int main() {
    Stack* myStack = nullptr;  // pointer to a stack object
    int choice, value;

    do {
        displayMenu();
        cin >> choice;

        if (choice != 1 && myStack == nullptr) {
            cout << "Please create a stack first (Option 1)." << endl;
            continue;
        }

        switch (choice) {
        case 1:
            // create the stack
            if (myStack == nullptr) {
                myStack = new Stack();
                cout << "Stack created successfully!" << endl;
            } else {
                cout << "Stack already exists." << endl;
            }
            break;

        case 2:
            // push an element
            cout << "Enter the value to push: ";
            cin >> value;
            myStack->push(value);
            cout << "Pushed " << value << " onto the stack." << endl;
            break;

        case 3:
            // pop an element
            myStack->pop();
            break;

        case 4:
            // display the top element
            if (myStack->top() != -1) {
                cout << "Top element: " << myStack->top() << endl;
            }
            break;

        case 5:
            // display the average of elements
            cout << "Average of stack elements: " << myStack->findAverage() << endl;
            break;

        case 6:
            // check if the stack is empty
            if (myStack->isEmpty()) {
                cout << "Stack is empty." << endl;
            } else {
                cout << "Stack is not empty." << endl;
            }
            break;

        case 7:
            // display all elements in the stack
            myStack->printStack();
            break;

        case 8:
            // exit
            cout << "Exiting program..." << endl;
            delete myStack;  
            break;

        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 8);

    return 0;
}
