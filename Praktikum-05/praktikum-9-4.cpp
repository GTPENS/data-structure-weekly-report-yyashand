// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
using namespace std;

class Queue {
private:
    struct Node {
        int value;
        Node* next;
    };

    Node* head = nullptr;
    int count = 0;

public:
    // Function to remove an element from the queue (dequeue)
    int remove() {
        if (isEmpty()) {
            throw std::invalid_argument("Queue is empty"); // Use std::invalid_argument
        }
        int value = head->value;
        Node* temp = head;
        head = head->next;
        delete temp;
        count--;
        return value;
    }

    bool isEmpty() const {
        return count == 0;
    }

    void print() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    using namespace std; // Include here for this specific scope

    Queue q;
    for (int i = 1; i <= 100; i++) {
        q.add(i); // Assuming you have an add function implemented
    }
    for (int i = 1; i <= 50; i++) {
        q.remove();
    }
    q.print();
    return 0;
}


