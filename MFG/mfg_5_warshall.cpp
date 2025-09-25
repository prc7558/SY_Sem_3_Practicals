#include <iostream>
#include <iomanip>
using namespace std;

const int sized = 4;
const int INF = 1e3;

int dist[sized][sized] = {
    {0,   15,  6,   8},
    {INF, 0,   15,  1},
    {8,   INF, 0,   3},
    {INF, 2,   INF, 0}
};

void print_matrix() {
    cout << endl;
    for (int i = 0; i < sized; i++) {
        for (int j = 0; j < sized; j++) {
            if (dist[i][j] >= INF)
                cout << setw(5) << "INF";
            else
                cout << setw(5) << dist[i][j];
        }
        cout << endl;
    }
}

void warshall() {
    for (int k = 0; k < sized; k++) {
        cout << "\nConsidering k = " << k << ":\n";
        for (int i = 0; i < sized; i++) {
            for (int j = 0; j < sized; j++) {
                if (dist[i][k] >= INF || dist[k][j] >= INF) continue;

                int through = dist[i][k] + dist[k][j];
                if (through < dist[i][j]) {
                    cout << "dist[" << i << "][" << j << "] ";
                    if (dist[i][j] >= INF) cout << "(INF)";
                    else cout << "(" << dist[i][j] << ")";
                    cout << " > dist[" << i << "][" << k << "] + dist[" 
                         << k << "][" << j << "] ";
                    cout << "(" << dist[i][k] << "+" << dist[k][j] << ")"
                         << " => update to " << through << "\n";
                    dist[i][j] = through;
                }
            }
        }
        
        print_matrix();
    }
}

int main() {
    cout << "Initial Matrix:";
    print_matrix();

    cout << "---------------" << endl;
    warshall();
    cout << "---------------" << endl;

    cout << "Final Shortest Paths Matrix:";
    print_matrix();

    return 0;
}
