#include <iostream>
#include <string>
using namespace std;

//~~~BASE CLASS~~~
class staff {
protected:
    string name, qualification;
    int ID, salary, exp_yrs;
public:
    void getinfo() {
        cout << "Enter the name: ";		getline(cin, name);
        cout << "Enter the staff ID: ";		cin >> ID; cin.ignore();
        cout << "Enter the qualification: "; getline(cin, qualification);
        cout << "Enter the Salary: ";		cin >> salary;
        cout << "Enter no. of years of experience: ";
        cin >> exp_yrs;	cin.ignore();
    }
    
    void putinfo() {
        cout << "\nName: " << name
             << "\nStaff ID: " << ID
             << "\nQualification: " << qualification
             << "\nSalary: " << salary
             << "\nYears of Experience: " << exp_yrs << "\n";
    }
};

//~~~DERIVED ADMIN CLASS~~~
class admin : protected staff {
protected: string dept, designation;
public:
    void getadmin() {
        staff::getinfo();
        cout << "Enter Admin's Department: ";		getline(cin, dept);
        cout << "Enter Admin's Designation: ";	getline(cin, designation);
    }

    void putadmin() {
        staff::putinfo();
        cout << "Department: " << dept
             << "\nDesignation: " << designation << "\n";
    }
};

//~~~DERIVED TEACHER CLASS~~~
class teacher : protected staff {
protected: string subject, deprt;
public:
    void get_teach() {
        staff::getinfo();
        cout << "Enter Teacher's Department: ";		getline(cin, deprt);
        cout << "Enter Teacher's Subject: ";	getline(cin, subject);
    }

    void put_teach() {
        staff::putinfo();
        cout << "Department: " << deprt
             << "\nSubject: " << subject << "\n";
    }
};

//~~~DERIVED NON-TEACHING CLASS~~~
class non_teach : protected staff {
protected: string depart;
public:
    void get_non_teach() {
        staff::getinfo();
        cout << "Enter Non-Teaching Staff Department: "; getline(cin, depart);
    }

    void put_non_teach() {
        staff::putinfo();
        cout << "Department: " << depart << "\n";
    }
};

//~~~DERIVED*2 SUPPORT CLASS~~~
class support : protected non_teach {
protected: string role, shift;
public:
    void getsupport() {
        non_teach::get_non_teach();
        cout << "Enter Support Staff Role: ";	getline(cin, role);
        cout << "Enter Shift: ";	getline(cin, shift);
    }

    void putsupport() {
        non_teach::put_non_teach();
        cout << "Role: " << role
             << "\nShift: " << shift << "\n";
    }
};

//~~~DERIVED*2 TECHNICAL CLASS~~~
class technical : protected non_teach {
protected: string specialization, equipment_handled;
public:
    void gettechnical() {
        non_teach::get_non_teach();
        cout << "Enter Technical Specialization: ";	getline(cin, specialization);
        cout << "Enter Equipment Handled: "; getline(cin, equipment_handled);
    }

    void puttechnical() {
        non_teach::put_non_teach();
        cout << "Specialization: " << specialization
             << "\nEquipment Handled: " << equipment_handled << "\n";
    }
};

//~~~MAIN FUNCTION~~~
int main() {
	int i, asize, tsize, ssize, techsize;
	
	// Input & Display ADMIN Details
	cout << "Enter Number of Admins: ";  cin >> asize; cin.ignore();
	admin *a = new admin[asize];
	
	for (i=0; i < asize; i++) {
		cout << "\n--- Enter Admin Staff " << i+1 << " Details ---\n";
		a[i].getadmin();
	}
	
	cout << "\n--- Admin Staff Details ---\n";
	for (i=0; i < asize; i++) {
		cout << "--- Admin Staff " << i+1 << " Details ---";
		a[i].putadmin();
		cout << "----------------------------------\n";
	}
	
	// Input & Display TEACHER Details
    cout << "\nEnter Number of Teachers: ";  cin >> tsize; cin.ignore();
    teacher *t = new teacher[tsize];
    
    for (i=0; i < tsize; i++) {
		cout << "\n--- Enter Teacher Staff " << i+1 << " Details ---\n";
        t[i].get_teach();
    }
    
    cout << "\n--- Teacher Staff Details ---\n";
    for (i=0; i < tsize; i++) {
		cout << "--- Teacher Staff " << i+1 << " Details ---";
        t[i].put_teach();
        cout << "----------------------------------\n";
    }
    
    // Input & Display SUPPORT Details    
    cout << "\nEnter Number of Support Staff: ";  cin >> ssize; cin.ignore();
    support *s = new support[ssize];
    
    for (i=0; i<ssize; i++) {
        cout << "\n--- Enter Support Staff " << i+1 << " Details ---\n";
        s[i].getsupport();
    }
    
    cout << "\n--- Support Staff Details ---\n";
    for (i=0; i<ssize; i++) {
        cout << "--- Support Staff " << i+1 << " Details ---";
        s[i].putsupport();
        cout << "----------------------------------\n";
    }
    
    // Input & Display TECHNICAL Details
    cout << "\nEnter Number of Technical Staff: "; cin >> techsize; cin.ignore();
    technical *tech = new technical[techsize];
    
    for (i=0; i<techsize; i++) {
        cout << "\n--- Enter Technical Staff " << i+1 << " Details ---\n";
        tech[i].gettechnical();
    }
    
    cout << "\n--- Technical Staff Details ---\n";
    for (i=0; i<techsize; i++) {
        cout << "--- Technical Staff " << i+1 << " Details ---";
        tech[i].puttechnical();
        cout << "----------------------------------\n";
    }
    
    //~~~cleanup~~~
    delete[] a; delete[] t; delete[] s; delete[] tech;
    return 0;
}
