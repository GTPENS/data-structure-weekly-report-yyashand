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

//Fungsi menambahkan node
void newNode(Node* prev_node, int new_data) {
    if (prev_node == NULL) {
        cout << "The given previous node cannot be NULL" << endl;
        return;
    }

    Node* new_node = new Node;
    new_node->data = new_data;
    new_node->next = prev_node->next;
    prev_node->next = new_node;
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

    cout << "List awal:" << endl;
    list();

    // Menambahkan data setelah 20
    int new_data = 55;
    Node* prev_node = head;
    while (prev_node != NULL && prev_node->data != 20) {
        prev_node = prev_node->next;
    }

    if (prev_node == NULL) {
        cout << "Data tidak ditemukan" << endl;
    }
    else {
        newNode(prev_node, new_data);
        cout << "List setelah ditambahkan data baru:" << endl;
        list();
    }

    return 0;
}
