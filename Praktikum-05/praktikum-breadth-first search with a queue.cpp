// Nama : Tiyyasha Ananda Mufti Hanifah
// NRP  : 5223600011

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// Mendefinisikan struktur node untuk merepresentasikan simpul dalam graf
struct Node {
    int value; // Nilai simpul
    vector<int> neighbors; // Daftar node neighbors 
    bool visited; // Status kunjungan simpul (dikunjungi atau belum)
};

// Fungsi BFS untuk melakukan pencarian breadth-first pada graf
void BFS(vector<Node>& graph, int start) {
    // Menginisialisasi queue untuk menyimpan simpul yang akan dikunjungi
    queue<Node*> q;

    // Menandai node awal sebagai dikunjungi dan menambahkannya ke antrian
    graph[start].visited = true;
    q.push(&graph[start]);

    // Melakukan iterasi sampai antrian kosong
    while (!q.empty()) {
        // Mengambil node terdepan dari antrian
        Node* current = q.front();
        q.pop();

        // Menampilkan nilai node yang sedang dikunjungi
        cout << current->value << " ";

        // Mengunjungi semua node neighbors yang belum dikunjungi
        for (int neighbor : current->neighbors) {
            if (!graph[neighbor].visited) {
                graph[neighbor].visited = true;
                q.push(&graph[neighbor]);
            }
        }
    }
}

int main() {
    // Mendefinisikan contoh graf dengan daftar neighbors untuk setiap node
    vector<Node> graph(5);
    graph[0].value = 0;
    graph[0].neighbors = { 1, 2 };
    graph[1].value = 1;
    graph[1].neighbors = { 0, 3 };
    graph[2].value = 2;
    graph[2].neighbors = { 0, 4 };
    graph[3].value = 3;
    graph[3].neighbors = { 1 };
    graph[4].value = 4;
    graph[4].neighbors = { 2 };

    // Memulai pencarian BFS dari node 0
    cout << "BFS Traversal: ";
    BFS(graph, 0);

    return 0;
}
