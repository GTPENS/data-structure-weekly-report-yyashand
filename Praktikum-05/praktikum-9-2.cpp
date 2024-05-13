// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
using namespace std;

class Node {
public:
    int value;
    Node* next;

    Node(int v, Node* n) {
        value = v;
        next = n;
    }

    int getValue() const { // Use const for getters
        return value;
    }

    Node* getNext() const { // Use const for getters
        return next;
    }
};

class Queue {
private:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

public:
    int size() const { // Use const for non-modifying functions
        return count;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->getValue() << " ";
            temp = temp->getNext();
        }
        cout << endl;
    }

    int peek() {
        if (isEmpty()) {
            throw invalid_argument("Queue is empty"); // Use std::invalid_argument
        }
        return head->getValue();
    }

};
