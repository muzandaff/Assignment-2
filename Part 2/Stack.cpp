#include "Stack.h"
#include <iostream>

using namespace std;

bool Stack::isEmpty() {
    return stackList.empty();
}

void Stack::push(int value) {
    stackList.push_front(value);
}

void Stack::pop() {
    if (!isEmpty()) {
        cout << "Popped: " << stackList.front() << endl;
        stackList.pop_front();
    } else {
        cout << "Stack is empty. Cannot pop." << endl;
    }
}

int Stack::top() {
    if (!isEmpty()) {
        return stackList.front();
    } else {
        cout << "Stack is empty. No top element." << endl;
        return -1;
    }
}

double Stack::findAverage() {
    if (!isEmpty()) {
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

void Stack::printStack() {
    if (!isEmpty()) {
        stackList.print_list();
    } else {
        cout << "Stack is empty." << endl;
    }
}

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
