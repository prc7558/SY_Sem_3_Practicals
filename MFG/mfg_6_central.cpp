#include <iostream>
#include <algorithm>
using namespace std;

// Function to calculate mean
double average(int scores[], int n) {
    double sum=0;
    for (int i=0; i<n; i++) sum += scores[i];
    return sum/n;
}

// Function to calculate median
double middle(int scores[], int n) {
    sort(scores, scores+n);
    if (!(n%2)) return (scores[n/2-1]+scores[n/2])/2.0;
    else return scores[n/2];
}

// Function to calculate mode
int most(int scores[], int n) {
    int maxCount=0, mode=scores[0];

    for (int i=0; i<n; i++) {
        int count=0;
        for (int j=0; j<n; j++)
			if (scores[i]==scores[j]) count++;
        if (count > maxCount) {
            maxCount = count;
            mode = scores[i];
        }
    } return mode;
}

int main() {
    int n;
    cout << "Enter the number of students: ";
    cin >> n;
    
    int scores[n];
    
    cout << "Enter the scores of " << n << " students: ";
    for (int i=0; i<n; i++)
        cin >> scores[i];
    
    // Calculate mean, median, and mode
    double mean = average(scores, n);
    double median = middle(scores, n);
    int mode = most(scores, n);
    
    // Output results
    cout << "\nResults:\n";
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
    
    return 0;
}
