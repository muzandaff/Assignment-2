#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

#include <iostream>

using namespace std;

// Node structure for a singly linked list
template <typename Item_Type>
struct Node {
    Item_Type data;
    Node* next;

    Node(const Item_Type& item);
};

// Single Linked List class
template <typename Item_Type>
class Single_Linked_List {
private:
    Node<Item_Type>* head;
    Node<Item_Type>* tail;
    size_t num_items;

public:
    // Constructor
    Single_Linked_List();

    // Destructor
    ~Single_Linked_List();

    // push_front
    void push_front(const Item_Type& item);

    // push_back
    void push_back(const Item_Type& item);

    // pop_front
    void pop_front();

    // pop_back
    void pop_back();

    // front
    Item_Type front() const;

    // back
    Item_Type back() const;

    // empty
    bool empty() const;

    // size
    size_t size() const;

    // insert with index validation
    void insert(size_t index, const Item_Type& item);

    // remove
    bool remove(size_t index);

    // find
    size_t find(const Item_Type& item) const;

    // print the list
    void print_list() const;

    // print empty status
    void print_empty_status() const;
};

#include "Single_Linked_List.cpp" 
#endif
