// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
using namespace std;

void insertionSort() {
    int comparisons = 0; // Initialize comparison counter
    int shifts = 0;      // Initialize shift counter

    for (int i = 1; i < MAX; i++) {
        int current = Data[i];
        int j = i - 1;
        while (j >= 0 && Data[j] > current) {
            comparisons++; // Increment comparison count
            Data[j + 1] = Data[j];
            shifts++;       // Increment shift count
            j--;
        }
        Data[j + 1] = current;

        // Print the array after each iteration
        cout << "\nIteration " << i << ":" << endl;
        for (int k = 0; k < MAX; k++) {
            cout << Data[k] << " ";
        }
    }

    cout << "\nComparisons: " << comparisons << endl; // Print total comparisons
    cout << "Shifts: " << shifts << endl;            // Print total shifts
}
