// Write a program to track rainfall data for 3 cities over 4 months.
// Using a 2D array, we can store the data, calculate the average rainfall for each city
// display the rainfall data in a tabular format.

#include<iostream>
#include<iomanip>
using namespace std;

void getdata(float rain_data[3][4]) {
    for (int i=0; i<3; i++) {
        cout << "Enter Rainfall data (in mm) for City " << i+1 << ": \n";
        for (int j=0; j<4; j++) {
            cout << " Month " << j+1 << ": ";
            cin >> rain_data[i][j];
        }
    }
}

void showdata(float rain_data[3][4]) {
    int i, j;
	float sum=0, total=0;
    
    cout << "\n City    |    Month 1   |    Month 2    |    Month 3    |    Month 4    |    Average \n";
    for (i=0; i<3; i++) {
        cout << "City " << i+1 << "   | ";
        for (sum=0, j=0; j<4; j++) {
            cout << setw(11) << fixed << setprecision(3) << rain_data[i][j] << "\t|";
            sum += rain_data[i][j];
        }
        cout << setw(11) << fixed << setprecision(3) << sum/4 << "\n";
    }
    
    cout << "Average  | ";
    for (j=0; j<4; j++) {
        for (sum=0, i=0; i<3; i++) {
            sum += rain_data[i][j];
            total += rain_data[i][j];
        }
        cout << setw(11) << fixed << setprecision(3) << sum/3 << "\t|";
    }
    cout << setw(11) << fixed << setprecision(3) << total/12;
}

int main() {
    float rain_data[3][4];    
    getdata(rain_data);
    showdata(rain_data);
    
    return 0;
}
