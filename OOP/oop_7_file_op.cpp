#include<iostream>
#include<fstream>
#include<string>
#include<limits>
using namespace std;

class inventory {
    string name;
    int itemID, quantity;
    double price;

public:
    void input();
    void display();
    void saveToFile(bool append = true);
};

void inventory::input() {
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "\nEnter name of item: ";
    getline(cin, name);
    cout << "Enter Item ID: ";
    cin >> itemID;
    cout << "Enter Quantity of item: ";
    cin >> quantity;
    cout << "Enter Price of item: ";
    cin >> price;
}


void inventory::display() {
    cout << "\n-------------------------------";
    cout << "\nName:  " << name;
    cout << "\nItem ID:  " << itemID;
    cout << "\nQuantity:  " << quantity;
    cout << "\nPrice:  " << price;
    cout << "\n-------------------------------";
}

void inventory::saveToFile(bool append) {
    ofstream fobj;
    if (append)
        fobj.open("TextFileNew.txt", ios::app);
    else
        fobj.open("TextFileNew.txt", ios::out);

    fobj << name << endl
         << itemID << endl
         << quantity << endl
         << price << endl;
    fobj.close();
}

int main() {
    inventory obj[3];

    cout << "=== Enter details for 3 inventory items ===\n";

    for (int i = 0; i < 3; i++) {
        cout << "\nItem " << i + 1 << ": ";
        obj[i].input();
        obj[i].saveToFile(i != 0);
    }

    cout << "\n=== Displaying all 3 inventory items ===\n";
    for (int i = 0; i < 3; i++) {
        cout << "\nItem " << i + 1 << ":";
        obj[i].display();
    }

    return 0;
}
