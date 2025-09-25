#include<iostream>
#include<limits>
#include<stdexcept>
using namespace std;

class division {
private:
	double a,b;
public:
	void accept();
	void calculate();
};

void division::accept() {
	cout << "Enter any two Numbers: ";
    if (!(cin >> a >> b)) {
        cin.clear();  // Clear error flags
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw runtime_error("Invalid input! Please enter numeric values.");
    }
}

void division::calculate() {
	if (b==0) throw runtime_error("#DIV/0! Divide by zero error!");
	cout << "\nDivision = " << a/b;
}

int main() {
	division obj;
    try {
        obj.accept();
        obj.calculate();
    }
    catch (const runtime_error &e) {
        cout << e.what() << endl;
    }
    catch (...) {  // Catch-all for other exceptions
        cout << "An unknown error occurred!" << endl;
    }
    
	return 0;
}
