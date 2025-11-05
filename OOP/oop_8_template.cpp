#include <iostream>
using namespace std;

template <class T>
void sel(T A[], int n) {
    int i, j, minIndex;
    T temp;
    
    for (i = 0; i < n - 1; i++) {
        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (A[j] < A[minIndex])
                minIndex = j;
        }
        temp = A[i];
        A[i] = A[minIndex];
        A[minIndex] = temp;
    }

    cout << "\nSorted array: ";
    for (i = 0; i < n; i++) {
        cout << " " << A[i];
    }
    cout << endl;
}

int main() {
    int choice, n, i;
    int A[10];
    float B[10];

    cout << "-----------------------";
    do {
        cout << "\n1. Integer";
        cout << "\n2. Float";
        cout << "\n3. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "\nEnter Total Number of Integer Elements: ";
                cin >> n;
                cout << "Enter Integer Elements: ";
                for (i = 0; i < n; i++)
                    cin >> A[i];
                sel(A, n);
                break;
            }
            case 2: {
                cout << "\nEnter Total Number of Float Elements: ";
                cin >> n;
                cout << "Enter Float Elements: ";
                for (i = 0; i < n; i++)
                    cin >> B[i];
                sel(B, n);
                break;
            }
            case 3:
                cout << "Program Exited Successfully **********" << endl;
                exit(0);
            default:
                cout << "\nInvalid Choice!";
        }
    } while (choice != 3);

    return 0;
}
