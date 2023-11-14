#include "ExpressionManager.h"
#include <stack>
#include <iostream>

using namespace std;

bool ExpressionManager::isBalanced(const string& expression) {
    stack<char> stack;
    for (char ch : expression) {
        switch (ch) {
            case '{': case '(': case '[':
                stack.push(ch);
                break;
            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;
            case ')':
                if (stack.empty() || stack.top() != '(') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
        }
    }
    return stack.empty();
}

int ExpressionManager::getPrecedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/' || op == '%') return 2;
    return 0;
}

bool ExpressionManager::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%';
}

string ExpressionManager::convertInfixToPostfix(const string& infix) {
    if (!isBalanced(infix)) {
        cerr << "Invalid expression: unbalanced parentheses.\n";
        return "";
    }

    stack<char> stack;
    string postfix;

    for (char ch : infix) {
        if (isspace(ch)) continue;

        if (isOperator(ch)) {
            while (!stack.empty() && getPrecedence(stack.top()) >= getPrecedence(ch)) {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (!stack.empty() && stack.top() != '(') {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop(); // Remove '(' from stack
        } else {
            postfix += ch; // Operand
        }
    }

    while (!stack.empty()) {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}
