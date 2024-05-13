// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <cstdlib> // For `srand` and `rand`
using namespace std;

const int MAX = 10; // Maximum number of elements

// Function to swap two integers
void swap(int* a, int* b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort algorithm
void selectionSort() {
    for (int i = 0; i < MAX - 1; i++) {
        int minIndex = i; // Index of the current minimum element
        for (int j = i + 1; j < MAX; j++) {
            if (Data[minIndex] > Data[j]) {
                minIndex = j; // Update the minimum index if a smaller element is found
            }
        }
        swap(&Data[i], &Data[minIndex]); // Swap the current minimum element with the element at the minimum index
    }
}

int main() {
    srand(0); // Seed the random number generator

    // Generate random numbers and print the unsorted data
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        Data[i] = rand() % 1000 + 1; // Generate random number between 1 and 1000
        cout << "\nData ke " << i << " : " << Data[i] << endl;
    }

    selectionSort(); // Apply selection sort

    // Print the sorted data
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
