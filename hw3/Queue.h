#ifndef QUEUE_H
#define QUEUE_H

// For size_t
#include <cstddef> 

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(const T& item);
    T dequeue();
    T front() const;
    bool isEmpty() const;
    // Ensure this matches with the definition
    size_t size() const;  

private:
    struct Node {
        T data;
        Node* next;
    };
    Node* frontNode;
    Node* rearNode;
    size_t currentSize;
};

#include "Queue.cpp" 
#endif // QUEUE_H
