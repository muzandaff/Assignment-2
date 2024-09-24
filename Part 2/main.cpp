#include <iostream>
#include <numeric>  
#include "Single_Linked_List.h" 

using namespace std;

class Stack {
private:
    Single_Linked_List<int> stackList;

public:
    // check to see if the stack is empty
    bool isEmpty() {
        return stackList.empty();
    }

    // push an element onto the stack
    void push(int value) {
        stackList.push_front(value);
    }

    // pop an integer from the stack 
    void pop() {
        if (!isEmpty()) {
            cout << "Popped: " << stackList.front() << endl;
            stackList.pop_front();
        } else {
            cout << "Stack is empty. Cannot pop." << endl;
        }
    }

    // print the top element of the stack
    int top() {
        if (!isEmpty()) {
            return stackList.front();
        } else {
            cout << "Stack is empty. No top element." << endl;
            return -1;  // Indicate an empty stack
        }
    }

    // calculate average of the stack elements
    double findAverage() {
        if (!isEmpty()) {
            // Accumulate the stack elements
            Node<int>* current = stackList.head;
            int sum = 0;
            size_t count = 0;

            while (current != nullptr) {
                sum += current->data;
                current = current->next;
                count++;
            }

            return static_cast<double>(sum) / count;
        } else {
            cout << "Stack is empty. No elements to average." << endl;
            return 0;
        }
    }

    // print stack
    void printStack() {
        if (!isEmpty()) {
            stackList.print_list();
        } else {
            cout << "Stack is empty." << endl;
        }
    }
};

// menu for effieciecy 
void displayMenu() {
    cout << "\n--- Stack Operations Menu ---\n";
    cout << "1. Create a stack\n";
    cout << "2. Push an element\n";
    cout << "3. Pop an element\n";
    cout << "4. Display top element\n";
    cout << "5. Display average of elements\n";
    cout << "6. Check if stack is empty\n";
    cout << "7. Display all elements in the stack\n";
    cout << "8. Exit\n";
    cout << "Enter your choice: ";
}

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
