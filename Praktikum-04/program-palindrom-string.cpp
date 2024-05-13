// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <string>
#include <algorithm> 
using namespace std;

bool isPalindrome(const string& str) {
    string temp = str;
    transform(temp.begin(), temp.end(), temp.begin(), ::tolower);

    int len = temp.length();
    for (int i = 0; i < len / 2; ++i) {
        if (temp[i] != temp[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int main() {
    string str;
    cout << "Enter a string: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout << str << " is a palindrome." << endl;
    }
    else {
        cout << str << " is not a palindrome." << endl;
    }

    return 0;
}
