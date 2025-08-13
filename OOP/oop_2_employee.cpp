// Develop a program in C++ to create a database of an employee's information system
// containing the following fields: Name, employee ID, Department,
// Date of Joining, Contact address, Telephone number etc.
// Construct the database with suitable member functions to accept
// print employee details. Make use of constructor types, destructor
// static members, inline function and dynamic memory allocation using
// operators-new and delete.

#include<iostream>
#include<string>
using namespace std;

class employee {
	protected:
		// Data Members
		string name, department, date, address;
		int emp_id;
		long long contact;
		static int count; // Static Data Member
	
	public:
		// Member Functions to accept & print data members and Multiple Constructors in a class
		void getdata();
		void showdata();
		
		// Default Constructor
		employee() {
			cout << "Employee object created (Constructor called) " << endl;
			name = "N/A";
			department = "N/A";
			date = "N/A";
			address = "N/A";
			emp_id = 0;
			contact = 0;
			count++;
		}
		
		// Parameterized Constructor
		employee(string n, string dept, string doj, string addr, int id, long long cont) {
			cout << "Employee object created (Parameterized Constructor called) for ID: " << id << endl;
			name = n;
			department = dept;
			date = doj;
			address = addr;
			emp_id = id;
			contact = cont;
			count++;
		}
		
		// Copy Constructor
		employee(const employee &emp) {
			name = emp.name;
			emp_id = emp.emp_id;
			department = emp.department;
			date = emp.date;
			address = emp.address;
			contact = emp.contact;
			cout << "\nEmployee object created (Copy Constructor called) for ID: " << emp_id << endl;
			count++;
		}
		
		// Static Member Function
		static int getCount() {
			 return count;
		}
		
		// Inline function
		inline void title() {
			cout<<"\n----- Employee Management Systems -----";
		}

		// Destructor
		~employee() {
			cout << "\nEmployee object destroyed for Employee ID: " << emp_id;
			count--;
		}
};

void employee::getdata() {
	cout << "\nEnter Employee name: ";
	getline(cin, name);
	cout << "Enter Employee's department: ";
	getline(cin, department);
	cout << "Enter Date of Joining: ";
	getline(cin, date);
	cout << "Enter Employee's Address: ";
	getline(cin, address);
	cout << "Enter Emplyee ID: ";
	cin >> emp_id;
	cin.ignore();
	cout << "Enter Employee's Contact Number: ";
	cin >> contact;
	cin.ignore();
}

void employee::showdata() {
	cout << "\n Employee name: " << name;
	cout << "\n Employee department: " << department;
	cout << "\n Employee Date of Joining: " << date;
	cout << "\n Employee ID: " << emp_id;
	cout << "\n Employee Contact Number: " << contact;
	cout << "\n Employee Address: " << address << endl;
}

// Initialise Static Data Member
int employee::count = 0;

int main() {
	// Parameterized Contructor Called
	employee newEmployee("John Doe", "IT", "2023-01-15", "123 Main St", 101, 9876543210);
	newEmployee.title();
	cout << "\n--- Displaying PARAMETERISED Employee details ---";
	newEmployee.showdata(); 
	
	// Copy Constructor Called
	employee newEmployee2 = newEmployee;
	cout << "\n--- Displaying COPIED Employee details ---";
	newEmployee2.showdata();
	
	int i, n;
    cout << "\n\nEnter number of employees to add: ";
    cin >> n;
    cin.ignore();
	
	// Dynamic Memory (array) Allocation using new at runtime
	employee* emp = new employee[n];
	
	for (i=0; i<n; i++) {
		cout << "\n--- Enter details for Employee " << i + 1 << " ---";
		emp[i].getdata();
	}
	
	for (i=0; i<n; i++) {
		cout << "\n--- Displaying Employee No. " << i + 1 << " details ---";
		emp[i].showdata();
	}
	
	// Static Member Function Called
	cout << "\n Total number of employees = " << employee::getCount();
	
	// Dynamic Memory Deallocation using delete
	delete[] emp;
	
	return 0;
}