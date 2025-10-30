#include <iostream>
using namespace std;
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int n;  // number of pages

void DFS(int v) {
    int i;
    visited[v] = 1;
    cout << "Page" << v << " ";

    for (i = 0; i < n; i++)
        if (adj[v][i]==1 && !(visited[i])) DFS(i);
}

int main() {
    int i, j, start;

    cout << "Enter number of web pages (nodes): ";
    cin >> n;

    cout << "Enter adjacency matrix (links between pages):\n";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) cin >> adj[i][j];

    for (i = 0; i < n; i++) visited[i] = 0;

    cout << "Enter starting web page (0 to " << n-1 << "): ";
    cin >> start;

    cout << "\nIndexing order of web pages (DFS): ";
    DFS(start);

    return 0;
}
