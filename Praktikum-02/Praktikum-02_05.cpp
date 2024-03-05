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

// Fungsi untuk menghapus data pada posisi tertentu
void deleteNode(int value) {
    // Handle empty list case
    if (head == NULL) {
        cout << "Tidak bisa mengahpus data" << endl;
        return;
    }

    // Mengahapus data pada posisi pertama
    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    // Mencari node 
    Node* temp = head;
    Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    // Mencari data untuk dihapus
    if (temp == NULL) {
        cout << "Node with value " << value << " not found." << endl;
        return;
    }

    // Menghapus node
    prev->next = temp->next;
    delete temp;
}

int main() {
    newData(10);
    newData(20);
    newData(30);
    newData(40);

    cout << "List awal: " << endl;
    list();

    cout << "Menghapus data 20:" << endl;
    deleteNode(20);

    cout << "List baru:" << endl;
    list();

    return 0;
}
