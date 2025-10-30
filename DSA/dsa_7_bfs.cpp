#include <iostream>
using namespace std;

#define MAX 10

int adj[MAX][MAX];   // adjacency matrix
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;               // number of web pages (nodes)

// Enqueue operation
void enqueue(int v) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    rear++;
    queue[rear] = v;
}

// Dequeue operation
int dequeue() {
    int v;
    if (front == -1 || front > rear)
        return -1;
    v = queue[front];
    front++;
    return v;
}

// BFS traversal
void BFS(int start) {
    int i, current;
    enqueue(start);
    visited[start] = 1;

    cout << "\nIndexing order of web pages (BFS): ";
    while (front <= rear) {
        current = dequeue();
        cout << "Page" << current << " ";

        for (i = 0; i < n; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    int i, j, start;

    cout << "Enter number of web pages (nodes): ";
    cin >> n;

    cout << "Enter adjacency matrix (links between pages):\n";
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cin >> adj[i][j];
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    cout << "Enter starting web page (0 to " << n-1 << "): ";
    cin >> start;

    BFS(start);
    return 0;
}
