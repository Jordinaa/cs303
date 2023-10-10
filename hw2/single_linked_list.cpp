#include "single_linked_list.h"
#include <stdexcept>

using namespace std;

SingleLinkedList::SingleLinkedList() : head(nullptr), tail(nullptr), num_items(0) {}

SingleLinkedList::~SingleLinkedList() {
    while (!empty()) {
        pop_front();
    }
}

void SingleLinkedList::push_front(Employee* item) {
    Node* new_node = new Node(item);
    new_node->next = head;
    head = new_node;
    if (tail == nullptr) {
        tail = head;
    }
    num_items++;
}

void SingleLinkedList::push_back(Employee* item) {
    Node* new_node = new Node(item);
    if (empty()) {
        head = tail = new_node;
    } else {
        tail->next = new_node;
        tail = new_node;
    }
    num_items++;
}

void SingleLinkedList::pop_front() {
    if (empty()) return;
    Node* old_head = head;
    head = head->next;
    if (head == nullptr) {
        tail = nullptr;
    }
    delete old_head;
    num_items--;
}

void SingleLinkedList::pop_back() {
    if (empty()) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* prev = head;
        while (prev->next != tail) {
            prev = prev->next;
        }
        delete tail;
        tail = prev;
        tail->next = nullptr;
    }
    num_items--;
}

Employee* SingleLinkedList::front() const {
    if (empty()) throw runtime_error("List is empty!");
    return head->data;
}

Employee* SingleLinkedList::back() const {
    if (empty()) throw runtime_error("List is empty!");
    return tail->data;
}

bool SingleLinkedList::empty() const {
    return num_items == 0;
}

void SingleLinkedList::insert(size_t index, Employee* item) {
    if (index >= num_items) {
        push_back(item);
        return;
    }
    if (index == 0) {
        push_front(item);
        return;
    }

    Node* prev = head;
    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    Node* new_node = new Node(item);
    new_node->next = prev->next;
    prev->next = new_node;
    num_items++;
}

bool SingleLinkedList::remove(size_t index) {
    if (index >= num_items) return false;
    if (index == 0) {
        pop_front();
        return true;
    }
    if (index == num_items - 1) {
        pop_back();
        return true;
    }

    Node* prev = head;
    for (size_t i = 0; i < index - 1; i++) {
        prev = prev->next;
    }
    Node* to_remove = prev->next;
    prev->next = to_remove->next;
    delete to_remove;
    num_items--;
    return true;
}

size_t SingleLinkedList::find(Employee* item) const {
    Node* current = head;
    size_t index = 0;
    while (current) {
        if (current->data == item) return index;
        current = current->next;
        index++;
    }
    return num_items;
}
