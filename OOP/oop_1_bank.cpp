#include<iostream>
#include<string>
using namespace std;

class bank_acc {
    string name;
    string type;
    int number;
    float balance;
    float amount;

    public:
        void getinfo() {
            cout << "\n Enter Account Name: ";
            cin >> name;
            cout << " Enter Account Type (Savings/Current): ";
            cin >> type;
            cout << " Enter Account Number: ";
            cin >> number;
            cout << " Enter Current Account Balance: ";
            cin >> balance;
        }

        void deposit() {
            cout << "\n Enter Amount to be deposited: ";
            cin >> amount;
            balance += amount;
            cout << " Amount deposited successfully. \n";
            cout << "\n Account Balance: " << balance << endl;
        }

        void withdraw() {
            cout << "\n Enter Amount to be withdrawn: ";
            cin >> amount;
            if(amount > balance) {
                cout << " Insufficient balance! \n";
            } else {
                balance -= amount;
                cout << " Amount withdrawn successfully. \n";
                cout << "\n Account Balance: " << balance << endl;
            }
        }

        void dispinfo() {
            cout << "\n Account Name: " << name;
            cout << "\n Account Type: " << type;
            cout << "\n Account Number: " << number;
            cout << "\n Account Balance: " << balance << endl;
        }
};

int main(){
    int choice;
    bank_acc cust1;

    do {
        cout << "\n Enter choice: ";
        cout << "\n 1. Input your Account Details";
        cout << "\n 2. Deposit Amount";
        cout << "\n 3. Withdraw Amount";
        cout << "\n 4. Display Account Information";
        cout << "\n 5. Exit";
        cout << "\n Your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cust1.getinfo();
                break;
            case 2:
                cust1.deposit();
                break;
            case 3:
                cust1.withdraw();
                break;
            case 4:
                cust1.dispinfo();
                break;
            case 5:
                cout << "Exiting program. Thank You! \n";
                break;
            default:
                cout << "Invalid choice. Please try again. \n";
        }
    } while (choice != 5);

    return 0;
}