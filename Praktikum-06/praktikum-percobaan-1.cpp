// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <cstdlib> // for `rand` and `srand`
using namespace std;

const int MAX = 10; // Maximum number of elements
int Data[MAX];

// Function for insertion sort
void StraightInsertSort() {
    for (int i = 1; i < MAX; ++i) {
        int x = Data[i];
        int j = i - 1;

        while (x < Data[j] && j >= 0) {
            Data[j + 1] = Data[j];
            j--;
        }

        Data[j + 1] = x;
    }
}

int main() {
    srand(0); // Seed the random number generator

    // Generate random numbers
    cout << "\nDATA SEBELUM TERURUT (Unsorted Data)" << endl;
    for (int i = 0; i < MAX; ++i) {
        Data[i] = rand() % 1000 + 1; // Generate random numbers between 1 and 1000
        cout << "\nData ke " << i << " : " << Data[i] << endl;
    }

    StraightInsertSort(); // Perform insertion sort

    // Sorted data
    cout << "\n\nDATA SETELAH TERURUT (Sorted Data)" << endl;
    for (int i = 0; i < MAX; ++i) {
        cout << "\nData ke " << i << " : " << Data[i] << endl;
    }

    return 0;
}
