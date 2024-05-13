// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
using namespace std;

class List {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int count = 0;

    void add(int value) {
        Node* temp = new Node(value);
        if (head == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        count++;
    }
};

