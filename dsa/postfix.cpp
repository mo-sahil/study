#include <iostream>
#include <stack>
#include <cmath> // Include this for pow function

using namespace std;

bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

int performOperation(char operation, int operand1, int operand2) {
    switch (operation) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        default:  return 0;
    }
}

int evaluatePostfixExpression(const string& postfix) {
    stack<int> operandStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0'); // Convert char to int
        } else if (isOperator(c)) {
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();
            int result = performOperation(c, operand1, operand2);
            operandStack.push(result);
        }
    }

    return operandStack.top();
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    cin >> postfixExpression;

    int result = evaluatePostfixExpression(postfixExpression);
    cout << "Result: " << result << endl;

    return 0;
}
