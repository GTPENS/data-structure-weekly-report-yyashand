// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <queue>
using namespace std;

class StackUsingQueue {
private:
    queue<int> q;

public:
    void push(int value) {
        q.push(value);
    }

    int pop() {
        if (q.empty()) {
            throw runtime_error("Stack underflow"); // Handle empty stack
        }

        int temp = q.front();
        int size = q.size(); // Get the current queue size

        // Re-enqueue all elements except the last one
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        q.pop(); // Remove the last element (top of the stack)
        return temp;
    }

    int top() {
        if (q.empty()) {
            throw runtime_error("Stack underflow"); // Handle empty stack
        }

        int temp = q.front(); // Store the front element (top)
        int size = q.size(); // Get the current queue size

        // Re-enqueue all elements to maintain the queue order
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        q.push(temp); // Re-enqueue the stored top element (for maintaining queue order)

        return temp;
    }

    bool empty() const {
        return q.empty();
    }

    int getSize() const {
        return q.size();
    }
};

int main() {
    StackUsingQueue s;
    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Top: " << s.top() << endl;
    cout << "Popped: " << s.pop() << endl;
    cout << "Top: " << s.top() << endl;

    s.push(4);
    cout << "Top: " << s.top() << endl;

    cout << "Size: " << s.getSize() << endl;

    return 0;
}


