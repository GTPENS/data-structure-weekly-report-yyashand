// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <stack>
#include <string>
#include <algorithm> // for std::reverse

using namespace std;

// Function to check operator precedence (reverse order for prefix)
int precedence(char op) {
    switch (op) {
    case '^':
        return 3;
    case '*':
    case '/':
    case '%':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return -1; // Not an operator
    }
}

string infixToPrefix(string expn) {
    // Reverse the infix expression
    reverse(expn.begin(), expn.end());

    // Replace parentheses (')' becomes '(' and vice versa)
    for (int i = 0; i < expn.length(); i++) {
        if (expn[i] == '(') {
            expn[i] = ')';
        }
        else if (expn[i] == ')') {
            expn[i] = '(';
        }
    }

    // Convert the reversed infix expression to postfix
    stack<char> stk;
    string output;
    char temp;

    for (char ch : expn) {
        if (isalnum(ch)) {
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
                    output = ch + " " + output;
                }
                stk.push(ch);
                break;
            case '(':
                stk.push(ch);
                break;
            case ')':
                while (!stk.empty() && (temp = stk.top()) != '(') {
                    stk.pop();
                    output = ch + " " + output;
                }
                break;
            }
        }
    }

    // Append remaining operators from the stack (for complete postfix expression)
    while (!stk.empty()) {
        temp = stk.top();
        stk.pop();
        output = ch + " " + output;
    }

    // Reverse the postfix expression (which is now the prefix expression)
    reverse(output.begin(), output.end());

    return output;
}

int main() {
    string expn = "10+((3))*5/(16-4)";
    string prefix = infixToPrefix(expn);

    cout << "Infix Expn: " << expn << endl;
    cout << "Prefix Expn: " << prefix << endl;

    return 0;
}


