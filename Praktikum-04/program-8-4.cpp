/*
Nama	: Tiyyasha Ananda Mufti Hanifah
NRP		: 5223600011
*/

#include <iostream>
#include <stack>

using namespace std;

bool cekTanda(string tanda) {
    stack<char> stk;
    for (char ch : tanda) {
        switch (ch) {
        case '{':
        case '[':
        case '(':
            stk.push(ch);
            break;
        case '}':
            if (stk.empty() || stk.top() != '{') {
                return false;
            }
            stk.pop();
            break;
        case ']':
            if (stk.empty() || stk.top() != '[') {
                return false;
            }
            stk.pop();
            break;
        case ')':
            if (stk.empty() || stk.top() != '(') {
                return false;
            }
            stk.pop();
            break;
        }
    }
    return stk.empty(); // Check if all parentheses are matched
}

int main() {
    string tandaIn = "{()}[";
    bool value = cekTanda(tandaIn);

    cout << "Cek tanda: " << tandaIn << endl;
    cout << "Hasil: " << value << endl;

    return 0;
}
