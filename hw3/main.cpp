#include <iostream>
#include "ExpressionManager.h"
#include "Queue.h"

using namespace std;

int main() {
    // Demonstration of Infix to Postfix Conversion
    cout << "Infix to Postfix Conversion\n";
    ExpressionManager expMgr;
    string infixExp;

    cout << "Enter an infix expression: ";
    getline(cin, infixExp);

    string postfixExp = expMgr.convertInfixToPostfix(infixExp);
    if (!postfixExp.empty()) {
        cout << "Postfix Expression: " << postfixExp << "\n";
    }

    // Demonstration of Queue functionality
    cout << "\nQueue Demonstration\n";
    Queue<int> intQueue; // Queue of integers

    // Enqueue elements
    intQueue.enqueue(10);
    intQueue.enqueue(20);
    intQueue.enqueue(30);

    // Displaying the front element
    cout << "Front element: " << intQueue.front() << "\n";

    // Dequeue and display elements
    cout << "Dequeued: " << intQueue.dequeue() << "\n";
    cout << "Dequeued: " << intQueue.dequeue() << "\n";

    // Display current size
    cout << "Current Queue size: " << intQueue.size() << "\n";

    // Check if Queue is empty
    cout << "Is Queue empty? " << (intQueue.isEmpty() ? "Yes" : "No") << "\n";

    return 0;
}
