#ifndef STACK_H
#define STACK_H

#include "Single_Linked_List.h"
#include <iostream>

class Stack {
private:
    Single_Linked_List<int> stackList;

public:
    bool isEmpty();
    void push(int value);
    void pop();
    int top();
    double findAverage();
    void printStack();
};

void displayMenu();

#endif
