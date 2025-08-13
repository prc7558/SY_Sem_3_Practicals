#include <iostream>
using namespace std;

class SetOperations {
private:
    int *A, *B, *inter, *uni;
    int sizeA, sizeB, totalStudents;

    bool exists(int arr[], int size, int val) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == val)
                return true;
        }
        return false;
    }

public:
    void input() {
        cout << "\nEnter total number of students in the school: ";
        cin >> totalStudents;

        cout << "Enter number of students in the Drama Club: ";
        cin >> sizeA;
        A = new int[sizeA];
        cout << "Enter roll numbers of students in the Drama Club:\n";
        for (int i = 0; i < sizeA; ) {
            int x;
            cin >> x;
            if (!exists(A, i, x)) {
                A[i++] = x;
            } else {
                cout << "Duplicate! Enter a unique roll number: ";
            }
        }

        cout << "\nEnter number of students in the Science Club: ";
        cin >> sizeB;
        B = new int[sizeB];
        cout << "Enter roll numbers of students in the Science Club:\n";
        for (int i = 0; i < sizeB; ) {
            int x;
            cin >> x;
            if (!exists(B, i, x)) {
                B[i++] = x;
            } else {
                cout << "Duplicate! Enter a unique roll number: ";
            }
        }

        inter = new int[(sizeA < sizeB ? sizeA : sizeB)];
        uni = new int[sizeA + sizeB];
    }

    void intersection() {
        int interSize = 0;
        for (int i = 0; i < sizeA; i++) {
            for (int j = 0; j < sizeB; j++) {
                if (A[i] == B[j] && !exists(inter, interSize, A[i])) {
                    inter[interSize++] = A[i];
                    break;
                }
            }
        }

        cout << "\n Students in BOTH Drama and Science Club:\n";
        for (int i = 0; i < interSize; i++)
            cout << inter[i] << " ";
        cout << endl;
    }

    int unionSet() {
        int uniSize = 0;

        for (int i = 0; i < sizeA; i++)
            uni[uniSize++] = A[i];

        for (int i = 0; i < sizeB; i++) {
            if (!exists(A, sizeA, B[i])) {
                uni[uniSize++] = B[i];
            }
        }

        cout << "\n Students in AT LEAST ONE Club:\n";
        for (int i = 0; i < uniSize; i++)
            cout << uni[i] << " ";
        cout << endl;

        return uniSize;
    }

    void difference() {
        cout << "\n Students in the Drama Club ONLY:\n";
        for (int i = 0; i < sizeA; i++) {
            if (!exists(B, sizeB, A[i]))
                cout << A[i] << " ";
        }
        cout << endl;

        cout << "\n Students in the Science Club ONLY:\n";
        for (int i = 0; i < sizeB; i++) {
            if (!exists(A, sizeA, B[i]))
                cout << B[i] << " ";
        }
        cout << endl;
    }

    void neither(int unionCount) {
        int neitherCount = totalStudents - unionCount;
        if (neitherCount <= 0)
            cout << "\nAll students are in at least one club\n";
        else
            cout << "\nNumber of Students in NEITHER Club = " << neitherCount << endl;
    }

    void cleanup() {
        delete[] A;
        delete[] B;
        delete[] inter;
        delete[] uni;
    }
};

int main() {
    int totalRuns;
    cout << "How many sets of club data do you want to enter? ";
    cin >> totalRuns;

    SetOperations* objArray = new SetOperations[totalRuns];

    for (int i = 0; i < totalRuns; i++) {
        cout << "\n===== Club Membership Set " << (i + 1) << " =====\n";
        objArray[i].input();
        objArray[i].intersection();
        int unionCount = objArray[i].unionSet();
        objArray[i].difference();
        objArray[i].neither(unionCount);
        objArray[i].cleanup();
    }

    delete[] objArray;
    return 0;
}