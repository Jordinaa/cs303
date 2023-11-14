#include "Queue.h"
#include <stdexcept>

using namespace std;

template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), currentSize(0) {}

template <typename T>
Queue<T>::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

template <typename T>
void Queue<T>::enqueue(const T& item) {
    Node* newNode = new Node{item, nullptr};
    if (isEmpty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    ++currentSize;
}

template <typename T>
T Queue<T>::dequeue() {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    Node* temp = frontNode;
    T data = temp->data;
    frontNode = frontNode->next;
    delete temp;
    if (frontNode == nullptr) {
        rearNode = nullptr;
    }
    --currentSize;
    return data;
}

template <typename T>
T Queue<T>::front() const {
    if (isEmpty()) {
        throw runtime_error("Queue is empty");
    }
    return frontNode->data;
}

template <typename T>
bool Queue<T>::isEmpty() const {
    return frontNode == nullptr;
}

template <typename T>
size_t Queue<T>::size() const {
    return currentSize;
}
