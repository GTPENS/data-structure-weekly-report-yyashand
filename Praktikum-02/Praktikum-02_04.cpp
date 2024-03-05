/*
Nama  : Tiyyasha Ananda Mufti Hanifah
NRP   : 5223600011
*/

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* head = NULL;

void newData(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    }
    else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void list() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    newData(10);
    newData(20);
    newData(30);
    newData(40);

    list();

    return 0;
}
