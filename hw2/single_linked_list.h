#ifndef SINGLE_LINKED_LIST_H
#define SINGLE_LINKED_LIST_H

// used to for size_t on the m1 macs has a hard time using unsigned long so this took awhile to figure out but it works on the m1. 
#include <cstddef>

class Employee;

class SingleLinkedList {
private:
    struct Node {
        Employee* data;
        Node* next;
        Node(Employee* data_item, Node* next_ptr = nullptr) 
            : data(data_item), next(next_ptr) {}
    };

    Node* head;
    Node* tail;
    size_t num_items;

public:
    SingleLinkedList();
    ~SingleLinkedList();

    void push_front(Employee* item);
    void push_back(Employee* item);
    void pop_front();
    void pop_back();
    Employee* front() const;
    Employee* back() const;
    bool empty() const;
    void insert(size_t index, Employee* item);
    bool remove(size_t index);
    size_t find(Employee* item) const;
};

#endif // SINGLE_LINKED_LIST_H
