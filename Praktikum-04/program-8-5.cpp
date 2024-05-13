// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Function to check operator precedence
int precedence(char op) {
    switch (op) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
    case '%':
        return 2;
    case '^':
        return 3;
    default:
        return -1; // Not an operator
    }
}

string infixToPostfix(string expn) {
    stack<char> stk;
    string output;
    char temp;

    for (char ch : expn) {
        if (isdigit(ch)) {
            output += ch;
        }
        else {
            switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
            case '%':
            case '^':
                while (!stk.empty() && precedence(ch) <= precedence(stk.top())) {
                    temp = stk.top();
                    stk.pop();
                    output += " " + temp;
                }
                stk.push(ch);
                output += " ";
                break;
            case '(':
                stk.push(ch);
                break;
            case ')':
                while (!stk.empty() && (temp = stk.top()) != '(') {
                    stk.pop();
                    output += " " + temp + " ";
                }
                break;
            }
        }
    }

    while (!stk.empty()) {
        temp = stk.top();
        stk.pop();
        output += " " + temp;
    }

    return output;
}

int main() {
    string expn = "10+((3))*5/(16-4)";
    string postfix = infixToPostfix(expn);
    cout << "Infix Expn: " << expn << endl;
    cout << "Postfix Expn: " << postfix << endl;
    return 0;
}
