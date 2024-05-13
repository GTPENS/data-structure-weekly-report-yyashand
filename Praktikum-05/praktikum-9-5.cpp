// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
private:
    stack<int> stk1;
    stack<int> stk2;

public:
    QueueUsingStack() {}

    void add(int value) {
        stk1.push(value);
    }

    int remove() {
        if (stk2.empty()) {
            while (!stk1.empty()) {
                stk2.push(stk1.top());
                stk1.pop();
            }
        }

        int value = stk2.top();
        stk2.pop();
        return value;
    }
};

int main() {
    QueueUsingStack queue;
    queue.add(1);
    queue.add(11);
    queue.add(111);
    cout << queue.remove() << endl;
    queue.add(2);
    queue.add(21);
    queue.add(211);
    cout << queue.remove() << endl;
    cout << queue.remove() << endl;

    return 0;
}


