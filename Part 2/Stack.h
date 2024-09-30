#ifndef STACK_H
#define STACK_H

#include "Single_Linked_List.h"
#include <iostream>

class Stack {
private:
    Single_Linked_List<int> stackList; // using single linked list to implement the stack

public:
    bool isEmpty(); // check if empty
    void push(int value); // push element
    void pop(); //pop element
    int top(); // get top element 
    double findAverage(); // find average of stack
    void printStack(); // print stack
};

void displayMenu(); // display a menu

#endif
