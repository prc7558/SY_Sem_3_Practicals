#include<iostream>
#include<cmath>
using namespace std;

// ~~~OPERATOR OVERLOADING~~~
class complex {
protected:
	float real, imag;
	
public:
	// ~~~DEFAULT CONSTRUCTOR~~~
	complex() {
		real=0; imag=0;
	}
	
	//~~~PARAMETERISED CONSTRUCTOR~~~
	complex(float r, float i) {
		real=r; imag=i;
	}
	
	//~~~COPY CONSTRUCTOR~~~
	complex (const complex &c) {
		real=c.real; imag=c.imag;
	}
	
	//~~~OVERLOAD + USING MEMBER FUNCTION~~~
	complex operator+(const complex &c) {
		return complex(real+c.real, imag+c.imag);
	}
	
	//~~~OVERLOAD - & * USING FRIEND FUNCTION~~~
	friend complex operator-(const complex &c1, const complex &c2);
	friend complex operator*(const complex &c1, const complex &c2);
	
	//~~~OVERLOAD STREAM OPERATORS~~~
	//~~~EXTRACTION: (>>) & INSERTION: (<<) ~~~
	friend istream &operator>>(istream &inp, complex &c);  //no const - modify c
	friend ostream &operator<<(ostream &out, const complex &c);
};

//~~~FRIEND FUNCTION DEFINITION~~~
complex operator-(const complex &c1, const complex &c2) {
	return complex(c1.real-c2.real, c1.imag-c2.imag);
}

// (a+bi).(c+di) = (ac-bd)+(ad+bc)i
complex operator*(const complex &c1, const complex &c2) {
	return complex((c1.real*c2.real - c1.imag*c2.imag),
				   (c1.real*c2.imag + c1.imag*c2.real));
}

//~~~INPUT~~~
istream &operator>>(istream &inp, complex &c) {  //no const - modify c
    cout << "Enter real part: ";
    inp >> c.real;
    cout << "Enter imaginary part: ";
    inp >> c.imag;
    cout << endl;
    return inp;
}

//~~~OUTPUT~~~
ostream &operator<<(ostream &out, const complex &c) {
	out << c.real;
    out << ((c.imag>=0) ? "+" : "-");
    out << fabs(c.imag) << "i";
    return out;
}

int main() {
	complex c1, c2, sum, diff, prod;
	
	cout << "Enter first complex number: " << endl;
	cin >> c1;
	cout << "Enter second complex number: " << endl;
	cin >> c2;
	
	//~~~CALL OVERLOADED FUNCTIONS~~~
	sum = c1+c2;
	diff = c1-c2;
	prod = c1*c2;
	
	cout << "First Complex Number = " << c1 << endl;
	cout << "Second Complex Number = " << c2 << endl;
	cout << "Sum of Complex Number = " << sum << endl;
	cout << "Difference of Complex Number = " << diff << endl;
	cout << "Product of Complex Number = " << prod << endl;
	return 0;
}
