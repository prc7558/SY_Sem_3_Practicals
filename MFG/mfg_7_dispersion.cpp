#include <iostream>
#include <cmath>
using namespace std;

double Mean(int data[], int n) {
    double sum=0; int i=0;
    while (i<n) sum += data[i++];
    return sum/n;
}

double Variance(int data[], int n) {
    int i=0; double var=0, mean=Mean(data, n);
    while (i<n) var += pow((data[i++]-mean), 2);
    return var/n;
}

double StdDev(double var) {
    return sqrt(var);
}

int Range(int data[], int n) {
    int i, max=data[0], min=data[0];
    for(i=1; i<n; i++) {
        if (data[i]>max) max=data[i];
        if (data[i]<min) min=data[i];
    } return max-min;
}

int main() {
	// 2 Sample Data Define
    int groupA[] = {6, 8, 7, 5, 6, 9, 7, 8};
    int groupB[] = {10, 12, 13, 11, 10, 9, 8, 14};
    int sizeA = sizeof(groupA)/sizeof(groupA[0]);
    int sizeB = sizeof(groupB)/sizeof(groupB[0]);

    // Calculations for Group A
    int rangeA = Range(groupA, sizeA);
    double varianceA = Variance(groupA, sizeA);
    double stdDevA = StdDev(varianceA);

    // Calculations for Group B
    int rangeB = Range(groupB, sizeB);
    double varianceB = Variance(groupB, sizeB);
    double stdDevB = StdDev(varianceB);

    cout << "Group A: ";
    for (int i=0; i<sizeA; i++) cout << groupA[i] << " ";
    cout << "\nRange = " << rangeA << endl;
    cout << "Variance = " << varianceA << endl;
    cout << "Standard Deviation = " << stdDevA << endl;

    cout << "\nGroup B: ";
    for (int i=0; i<sizeB; i++) cout << groupB[i] << " ";
    cout << "\nRange = " << rangeB << endl;
    cout << "Variance = " << varianceB << endl;
    cout << "Standard Deviation = " << stdDevB << endl;

    return 0;
}
