/*
Nama	: Tiyyasha Ananda Mufti Hanifah
NRP		: 5223600011
*/

#include <iostream>

using namespace std;

class stack {
private:
    class Node {
    public:
        int data;
        Node* next;

        Node(int v, Node* n) : data(v), next(n) {}
    };

    Node* head = nullptr;
    int count = 0;

public:
    int hitung() {
        return count;
    }

    bool kosong() {
        return count == 0;
    }

    int list() {
        if (kosong()) {
            throw runtime_error("Tidak ada data.");
        }
        return head->data;
    }

    void push(int data) {
        head = new Node(data, head);
        count++;
    }

    int pop() {
        if (kosong()) {
            throw runtime_error("Tidak ada data.");
        }
        int data = head->data;
        head = head->next;
        count--;
        return data;
    }

    void dataBaru(int data) {
        if (kosong()) {
            push(data);
        }
        else {
            int temp = pop();
            dataBaru(data);
            push(temp);
        }
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    stack s;
    for (int i = 1; i <= 100; i++) {
        s.push(i);
    }
    for (int i = 1; i <= 50; i++) {
        s.pop();
    }
    s.print();
    return 0;
}
