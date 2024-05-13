// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <cstdlib> // for rand() and srand()

using namespace std;

const int MAX = 10; // Maximum array size

// Function to perform binary insertion sort
void binaryInsertionSort(int data[], int size) {
    for (int i = 1; i < size; i++) {
        int key = data[i]; // Store the current element as the key
        int j = i - 1; // Initialize the insertion index

        while (j >= 0 && key < data[j]) { // Binary search for the insertion point
            data[j + 1] = data[j]; // Shift elements to the right
            j--;
        }

        data[j + 1] = key; // Insert the key at the found position
    }
}

int main() {
    srand(0); // Seed the random number generator

    int data[MAX]; // Array to store the data

    // Generate random numbers and print the unsorted data
    cout << "DATA SEBELUM TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        data[i] = rand() % 1000 + 1; // Generate random number between 1 and 1000
        cout << "\nData ke " << i << " : " << data[i] << endl;
    }

    // Perform binary insertion sort
    binaryInsertionSort(data, MAX);

    // Print the sorted data
    cout << "\nDATA SETELAH TERURUT" << endl;
    for (int i = 0; i < MAX; i++) {
        cout << "\nData ke " << i << " : " << data[i] << endl;
    }

    return 0;
}
