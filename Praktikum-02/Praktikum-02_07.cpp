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

void insertBefore(int targetData, int newData) {
    // Create the new node
    Node* newNode = new Node;
    newNode->data = newData;

    // Check if the list is empty or if the target data is the head
    if (head == NULL || head->data == targetData) {
        newNode->next = head;
        head = newNode;
        return;
    }

    // Otherwise, traverse the list to find the node before the target
    Node* prev = head, * curr = head->next;
    while (curr != NULL && curr->data != targetData) {
        prev = curr;
        curr = curr->next;
    }

    // Handle the case where the target data is not found
    if (curr == NULL) {
        cout << "Target data not found in the list." << endl;
        return;
    }

    // Insert the new node
    newNode->next = curr;
    prev->next = newNode;
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

    cout << "List awal: " << endl;
    list();

    int targetData = 20, newDataToInsert = 15;
    insertBefore(targetData, newDataToInsert);

    cout << "List setelan ditambahkan " << newDataToInsert << " sebelum " << targetData << ": " << endl;
    list();

    return 0;
}
