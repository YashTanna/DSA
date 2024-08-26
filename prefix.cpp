#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

int prec(char op) {
    switch (op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '#':
            return 0;
    }
    return 0;
}

string infixToPrefix(string infix) {
    string prefix = "";
    stack<char> operators;
    stack<string> operands;
    reverse(infix.begin(), infix.end());

    for (char ch : infix) {
        if (isalnum(ch)) {
            string operand(1, ch);
            operands.push(operand);
        } else if (ch == ')') {
            operators.push(ch);
        } else if (ch == '(') {
            while (!operators.empty() && operators.top() != ')') {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string expression = op + operand1 + operand2;
                operands.push(expression);
            }
            if (!operators.empty() && operators.top() == ')') {
                operators.pop();
            }
        } else {
            while (!operators.empty() && prec(ch) <= prec(operators.top())) {
                char op = operators.top();
                operators.pop();

                string operand2 = operands.top();
                operands.pop();
                string operand1 = operands.top();
                operands.pop();

                string expression = op + operand1 + operand2;
                operands.push(expression);
            }
            operators.push(ch);
        }
    }

    while (!operators.empty()) {
        char op = operators.top();
        operators.pop();

        string operand2 = operands.top();
        operands.pop();
        string operand1 = operands.top();
        operands.pop();

        string expression = op + operand1 + operand2;
        operands.push(expression);
    }

    if (!operands.empty()) {
        prefix = operands.top();
    }

    return prefix;
}

int main() {
    string prefix = infixToPrefix("a+b*c-d/e");
    cout << prefix << endl;
    return 0;
}
