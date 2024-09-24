#ifndef SINGLE_LINKED_LIST_CPP
#define SINGLE_LINKED_LIST_CPP

#include "Single_Linked_List.h"

using namespace std;

// Node constructor
template <typename Item_Type>
Node<Item_Type>::Node(const Item_Type& item) : data(item), next(nullptr) {}

// Single_Linked_List constructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::Single_Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Single_Linked_List destructor
template <typename Item_Type>
Single_Linked_List<Item_Type>::~Single_Linked_List() {
    while (!empty()) {
        pop_front();
    }
}

// push_front
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_front(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        new_node->next = head;
        head = new_node;
    }
    num_items++;
}

// push_back
template <typename Item_Type>
void Single_Linked_List<Item_Type>::push_back(const Item_Type& item) {
    Node<Item_Type>* new_node = new Node<Item_Type>(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

// pop_front
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_front() {
    if (empty()) {
        return;
    }
    Node<Item_Type>* temp = head;
    head = head->next;
    delete temp;
    num_items--;

    if (empty()) {
        tail = nullptr;
    }
}

// pop_back
template <typename Item_Type>
void Single_Linked_List<Item_Type>::pop_back() {
    if (empty()) {
        return;
    }

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node<Item_Type>* current = head;
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;
        tail = current;
        tail->next = nullptr;
    }
    num_items--;
}

// front
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::front() const {
    if (!empty()) {
        return head->data;
    }
    throw runtime_error("List is empty");
}

// back
template <typename Item_Type>
Item_Type Single_Linked_List<Item_Type>::back() const {
    if (!empty()) {
        return tail->data;
    }
    throw runtime_error("List is empty");
}

// empty
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::empty() const {
    return num_items == 0;
}

// size
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::size() const {
    return num_items;
}

// insert
template <typename Item_Type>
void Single_Linked_List<Item_Type>::insert(size_t index, const Item_Type& item) {
    if (index > num_items) {  // Check if index is out of bounds
        cout << "Error: Index " << index << " is out of bounds. Valid indices: 0 to " << num_items << "." << endl;
        return;
    }

    if (index == 0) {
        push_front(item);
    } else if (index == num_items) {
        push_back(item);
    } else {
        Node<Item_Type>* new_node = new Node<Item_Type>(item);
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        num_items++;
    }

    cout << "Element inserted at index " << index << "." << endl;
}

// remove
template <typename Item_Type>
bool Single_Linked_List<Item_Type>::remove(size_t index) {
    if (index >= num_items) {
        return false;
    }
    if (index == 0) {
        pop_front();
    } else {
        Node<Item_Type>* current = head;
        for (size_t i = 0; i < index - 1; ++i) {
            current = current->next;
        }
        Node<Item_Type>* temp = current->next;
        current->next = temp->next;
        if (temp == tail) {
            tail = current;
        }
        delete temp;
        num_items--;
    }
    return true;
}

// find
template <typename Item_Type>
size_t Single_Linked_List<Item_Type>::find(const Item_Type& item) const {
    Node<Item_Type>* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) {
            return index;
        }
        current = current->next;
        index++;
    }
    return num_items;  // Return size if not found
}

// print the list
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print_list() const {
    if (empty()) {
        cout << "List is empty." << endl;
        return;
    }

    Node<Item_Type>* current = head;
    cout << "List: ";
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

// print empty status
template <typename Item_Type>
void Single_Linked_List<Item_Type>::print_empty_status() const {
    if (empty()) {
        cout << "Empty" << endl;
    } else {
        cout << "Not Empty" << endl;
    }
}

#endif
