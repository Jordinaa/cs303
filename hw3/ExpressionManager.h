#ifndef EXPRESSIONMANAGER_H
#define EXPRESSIONMANAGER_H

#include <string>

using namespace std;

class ExpressionManager {
public:
    string convertInfixToPostfix(const string& infix);
private:
    bool isBalanced(const string& expression);
    int getPrecedence(char op);
    bool isOperator(char ch);
};

#endif // EXPRESSIONMANAGER_H