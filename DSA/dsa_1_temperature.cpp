#include <iostream>
#include <iomanip>
using namespace std;

void getdata(float temperature[3][7]) {
    for (int i = 0; i < 3; i++) {
        cout << "Enter temperatures (Celsius) for City " << i + 1 << ":\n";
        for (int j = 0; j < 7; j++) {
            cout << "  Day " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }
}

void showdata(float temperature[3][7]) {
    float sum, total = 0;

    cout << "\n        Day    |";
    for (int i = 0; i < 3; i++) {
        cout << "     City " << i + 1 << "    |"; }
    cout << "  Daily Avg  \n";
    cout << "----------------------------------------------------------------------------\n";

    for (int j = 0; j < 7; j++) {
        cout << setw(11) << fixed << "Day  " << j + 1 << "   |";
        sum = 0;
        for (int i = 0; i < 3; i++) {
            cout << setw(11) << fixed << setprecision(3) << temperature[i][j] << "    |";
            sum += temperature[i][j];
            total += temperature[i][j];
        }
        cout << setw(11) << fixed << setprecision(3) << sum / 3 << endl;
    }
    
    cout << "----------------------------------------------------------------------------\n";
    cout << "    Weekly Avg |";
    for (int i = 0; i < 3; i++) {
        sum = 0;
        for (int j = 0; j < 7; j++)
            sum += temperature[i][j];
        cout << setw(11) << fixed << setprecision(3) << sum / 7 << "    |";
    }

    cout << setw(11) << fixed << setprecision(3) << total / 21;
}

int main() {
    float temperature[3][7];
    
    getdata(temperature);
    showdata(temperature);
    
    return 0;
}