// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <stack>
#include <sstream>
#include <string>
using namespace std;

// Fungsi untuk mengevaluasi postfix
int postfixEvaluate(string expn) {
    stack<int> stk;
    stringstream ss(expn); 
    string token;

    while (getline(ss, token, ' ')) { 
        if (isdigit(token[0])) {
            int value = stoi(token); 
            stk.push(value);
        }
        else {
            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();

            switch (token[0]) {
            case '+':
                stk.push(num1 + num2);
                break;
            case '-':
                stk.push(num1 - num2);
                break;
            case '*':
                stk.push(num1 * num2);
                break;
            case '/':
                stk.push(num1 / num2);
                break;
            default:
                
                return -1; 
            }
        }
    }

    if (stk.size() != 1) {
        
        return -1; 
    }

    return stk.top();
}

int main() {
    string expn = "6 5 2 3 + 8 * + 3 + *";
    int result = postfixEvaluate(expn);

    if (result == -1) {
        cout << "Invalid postfix expression!" << endl;
    }
    else {
        cout << "Given Postfix Expn: " << expn << endl;
        cout << "Result after Evaluation: " << result << endl;
    }

    return 0;
}



