#include <iostream>
using namespace std;

class shape {
public:
    double base, height;
	
	// Virtual function preference to base class first.
	// base class virtual getdata called in triangle shape.
    virtual void getdata() {
        cout << "Enter base & height: ";
        cin >> base >> height;
    }
    
    void show() {
        cout << "Shape base class show\n";
    }

    virtual void display() {
        cout << "Shape base class display\n";
    }

    virtual void disp_area() = 0;
};

class Triangle : public shape {
public:
    void display() override {
        cout << "Triangle with base = " << base << " & height = " << height << endl;
    }

    void disp_area() override {
        cout << "\nArea of Triangle = " << 0.5*base*height << endl;
    }
};

class Rectangle : public shape {
public:
	// base class getdata overriden, called in derived class.
	void getdata() override {
		cout << "Enter length & breadth: ";
		cin >> base >> height;
	}
	
    void display() override {
        cout << "Rectangle with length = " << base << " & breadth = " << height << endl;
    }

    void disp_area() override {
        cout << "\nArea of Rectangle = " << base * height << endl;
    }
};

class Circle : public shape {
public:
	// base class getdata overriden, called in derived class.
    void getdata() override {
        cout << "Enter radius: ";
        cin >> base;
    }

    void display() override {
        cout << "Circle with radius = " << base << endl;
    }

    void disp_area() override {
        cout << "\nArea of Circle = " << 3.14159*base*base << endl;
    }
};

void processShape(shape* ptr) {
    ptr->getdata();
    ptr->show();
    ptr->display();
    ptr->disp_area();
    cout << "---------------------------\n";
}

int main() {

	//shape pntr;	error- cannot declare object in abstract class
	  shape *ptr;
	
	  Triangle t;
    Rectangle r;
    Circle c;
    
    int choice;

    cout << "\nSelect shape to calculate area:\n";
    cout << "1. Triangle\n";
    cout << "2. Rectangle\n";
    cout << "3. Circle\n";
    cout << "4. All\n";
    cout << "Enter choice: ";
    cin >> choice;

    switch (choice) {
        case 1:
            ptr = &t;
            processShape(ptr);
            break;

        case 2:
            ptr = &r;
            processShape(ptr);
            break;

        case 3:
            ptr = &c;
            processShape(ptr);
            break;

        case 4:
            cout << "\n--- Triangle ---\n";
			      processShape(&t);

            cout << "\n--- Rectangle ---\n";
			      processShape(&r);
			
            cout << "\n--- Circle ---\n";
			      processShape(&c);
            break;

        default:
            cout << "Invalid choice.\n";
    }

    return 0;
}
