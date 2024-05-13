// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <vector>
using namespace std;

// Define Employee structure
struct Employee {
    string NIP;
    string NAMA;
};

// Function to compare employees based on NIP (ascending order)
bool compareNIPAscending(const Employee& e1, const Employee& e2) {
    return e1.NIP < e2.NIP;
}

// Function to compare employees based on NIP (descending order)
bool compareNIPDescending(const Employee& e1, const Employee& e2) {
    return e1.NIP > e2.NIP;
}

// Function to compare employees based on NAMA (ascending order)
bool compareNAMAAscending(const Employee& e1, const Employee& e2) {
    return e1.NAMA < e2.NAMA;
}

// Function to compare employees based on NAMA (descending order)
bool compareNAMADescending(const Employee& e1, const Employee& e2) {
    return e1.NAMA > e2.NAMA;
}

int main() {
    // Initialize employee data
    vector<Employee> employees = {
      {"12345", "Budi"},
      {"67890", "Andi"},
      {"45678", "Cici"},
      {"23456", "Dedi"},
      {"89012", "Eni"},
    };

    // Choose sorting method, order, and comparison function
    int choiceMethod;
    int choiceOrder;
    bool (*compareFunction)(const Employee&, const Employee&);

    cout << "Pilih metode pengurutan (1 - Insertion Sort, 2 - Selection Sort): ";
    cin >> choiceMethod;

    cout << "Pilih urutan pengurutan (1 - Ascending, 2 - Descending): ";
    cin >> choiceOrder;

    cout << "Pilih kriteria pengurutan (1 - NIP, 2 - NAMA): ";
    cin >> choiceMethod;

    if (choiceMethod == 1) {
        compareFunction = compareNIPAscending;
    }
    else if (choiceMethod == 2) {
        compareFunction = compareNIPDescending;
    }
    else if (choiceMethod == 3) {
        compareFunction = compareNAMAAscending;
    }
    else if (choiceMethod == 4) {
        compareFunction = compareNAMADescending;
    }
    else {
        cout << "Pilihan tidak valid!" << endl;
        return 0;
    }

    // Sort the employee data using the chosen method, order, and comparison function
    if (choiceMethod == 1) {
        insertion_sort(employees.begin(), employees.end(), compareFunction);
    }
    else if (choiceMethod == 2) {
        selection_sort(employees.begin(), employees.end(), compareFunction);
    }
    else {
        sort(employees.begin(), employees.end(), compareFunction);
    }

    // Print the sorted employee data
    cout << "\nData Pegawai yang Telah Diurutkan:" << endl;
    for (const Employee& employee : employees) {
        cout << "NIP: " << employee.NIP << ", NAMA: " << employee.NAMA << endl;
    }

    return 0;
}


