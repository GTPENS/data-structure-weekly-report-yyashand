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
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* search(int data) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

int main() {
    newData(1);
    newData(2);
    newData(3);
    newData(4);
    newData(5);

    list();

    int key = 3;
    Node* foundNode = search(key);

    if (foundNode == NULL) {
        cout << "Data " << key << " tidak ditemukan." << endl;
    }
    else {
        cout << "Data " << key << " ditemukan." << endl;
    }

    return 0;
}
