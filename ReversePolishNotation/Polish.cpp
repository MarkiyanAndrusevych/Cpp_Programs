#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

// Функція для пеервірки чи символ є оператором
bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// Фукнкція для визначення пріорітетності
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-') {
        return 1;
    } else if (ch == '*' || ch == '/') {
        return 2;
    } else {
        return 0;
    }
}

// Функція перетворення у зворотній полський запис
string infixToRPN(string infix) {
    stack<char> operators;
    string rpn;
    unordered_map<char, int> precedence;

    // Встановлюємо пріорітетність операторів
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;

    for (char ch : infix) {
        if (ch == ' ') {
            continue;
        } else if (isdigit(ch)) {
            // Додаємо операнд
            rpn += ch;
        } else if (isOperator(ch)) {
            // Забираємо оператори з вищим або рівним пріорітетом
            while (!operators.empty() && operators.top() != '(' && precedence[operators.top()] >= precedence[ch]) {
                rpn += operators.top();
                operators.pop();
            }
            operators.push(ch);
        } else if (ch == '(') {
            operators.push(ch);
        } else if (ch == ')') {
            //Забриємо оператори поки не буде '(' і додаємо їх до нашого виразу
            while (!operators.empty() && operators.top() != '(') {
                rpn += operators.top();
                operators.pop();
            }
            operators.pop();
        }
    }

    // Забираємо решту операторів та додаємо до виразу
    while (!operators.empty()) {
        rpn += operators.top();
        operators.pop();
    }

    return rpn;
}
// Функція для розрахунку зворотньої полської нотації
double evaluateRPN(string rpn) {
    stack<double> operands;
    for (char ch : rpn) {
        if (isdigit(ch)) {
            // Додати операнд в стек
            operands.push(ch - '0');
        } else if (isOperator(ch)) {
            // Pop 2 операнди і здійснити операцію
            double operand2 = operands.top();
            operands.pop();
            double operand1 = operands.top();
            operands.pop();
            switch (ch) {
                case '+':
                    operands.push(operand1 + operand2);
                    break;
                case '-':
                    operands.push(operand1 - operand2);
                    break;
                case '*':
                    operands.push(operand1 * operand2);
                    break;
                case '/':
                    operands.push(operand1 / operand2);
                    break;
            }
        }
    }
    return operands.top();
}

int main() {
    string infix = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
    string rpn = infixToRPN(infix);
    cout << "Infix: " << infix << endl;
    cout << "RPN: " << rpn << endl;
    cout<<"Final result: "<<evaluateRPN(rpn);
    return 0;
}