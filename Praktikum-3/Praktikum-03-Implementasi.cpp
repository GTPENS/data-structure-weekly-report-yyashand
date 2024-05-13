// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = NULL; // Pointer untuk head

// Fungsi untuk menyisipkan node di awal 
void insertAtBeginning(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
}

// Fungsi untuk menyisipkan node di akhir
void insertAtEnd(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Fungsi untuk membaca list
void displayList() {
    if (head == NULL) {
        cout << "List is empty!" << endl;
        return;
    }

    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

// Fungsi untuk mencari node
Node* searchNode(int data) {
    Node* temp = head;

    while (temp != NULL && temp->data != data) {
        temp = temp->next;
    }

    return temp;
}

// Fungsi untuk menghapus node
void deleteNode(int data) {
    Node* nodeToDelete = searchNode(data);

    if (nodeToDelete == NULL) {
        cout << "Node with data " << data << " not found!" << endl;
        return;
    }

    if (nodeToDelete == head) { // Deleting the first node
        head = nodeToDelete->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    }
    else if (nodeToDelete->next == NULL) { // Deleting the last node
        Node* prevNode = nodeToDelete->prev;
        prevNode->next = NULL;
    }
    else { // Deleting a node in the middle
        Node* prevNode = nodeToDelete->prev;
        Node* nextNode = nodeToDelete->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    delete nodeToDelete;
}

int main() {
    int choice, data;

    while (true) {
        cout << "\nMenu Pilihan Doubly Linked List:\n";
        cout << "1. Sisipkan di Awal\n";
        cout << "2. Sisipkan di Akhir\n";
        cout << "3. Tampilkan List\n";
        cout << "4. Cari Node\n";
        cout << "5. Hapus Node\n";
        cout << "6. Keluar\n";
        cout << "Masukkan pilihan Anda: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Masukkan data yang ingin disisipkan: ";
            cin >> data;
            insertAtBeginning(data);
            break;
        case 2:
            cout << "Masukkan data yang ingin disisipkan: ";
            cin >> data;
            insertAtEnd(data);
            break;
        case 3:
            displayList();
            break;
        case 4:
            cout << "Masukkan data yang ingin dicari: ";
            cin >> data;
            Node* foundNode = searchNode(data);
            if (foundNode == NULL) {
                cout << "Node dengan data " << data << " tidak ditemukan!" << endl;
            }
            else if (foundNode == head) {
                cout << "Data " << data << " ditemukan di awal list!" << endl;
            }
            else {
                cout << "Data " << data << " ditemukan!" << endl;
            }
        }
    }
}