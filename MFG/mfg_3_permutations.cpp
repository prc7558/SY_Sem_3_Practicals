#include <iostream>
using namespace std;

class permutation {
public:
	//~~~FACTORIAL~~~
    long long fact(int n) {
        long long f=1;
        for (int i=1; i<=n; i++) f*=i;
        return f;
    }
    
    //~~~PERMUTATION~~~
    long long nPr(int n, int r) {
        return (fact(n)/fact(n-r));
    }
    
    //~~~COMBINATION~~~
    long long nCr(int n, int r) {
        return (fact(n) / (fact(r)*fact(n-r)));
    }
    
    //~~~1st CASE~~~
    void competition(int t, int p, int m) {
        long long medals = nPr(t,m);
        long long certs  = nCr(t-m,p-m);
        long long total  = medals*certs;
        cout << "\n1. Total Number of ways = " << total << endl;
    }
    
    //~~~2nd CASE~~~
    void digitNumbers(int d[], int n, int k) {
    	//~~~TOTAL NUMBERS~~~
        int i=0, count=0, below4=0;
        long long total = nPr(n,k);
        
        //~~~EVEN NUMBERS~~~
        while(i<n) if(!(d[i++]%2)) count++;
        long long even = count*nPr(n-1, k-1);
        
        //~~~NUMBERS BELOW 400~~~
        for(int i=0;i<n;i++) if(d[i]<4) below4++;
        long long below400 = below4*nPr(n-1, k-1);
        
        //~~~DISPLAY~~~
        cout << "\na. Total " << k << "-digit numbers = " << total << endl;
        cout << "b. Even numbers = " << even << endl;
        cout << "c. Numbers below 400 = " << below400 << endl;
    }
    
    //~~~3rd CASE~~~
    void bothCases() {
    	int digits[6] = {1,2,3,4,5,6};
		competition(12, 5, 3);
		digitNumbers(digits, 6, 3);
	}
};

int main() {
	//~~~DIGITS FOR CASE 2~~~
    int ch, digits[6]={1,2,3,4,5,6};
    permutation obj;
    
    //~~~SWITCH CASE MENU~~~
    cout << "Menu:\n";
    cout << "1. Competition of 12 participants (top 5 arrangement)\n";
    cout << "2. 3-digit numbers from {1,2,3,4,5,6}\n";
    cout << "3. Run both cases\n";
    cout << "\nEnter choice (1, 2 or 3): ";
    cin >> ch;
    
    //~~~EXECUTE CASE FUNCTION~~~
    switch(ch) {
        case 1: obj.competition(12, 5, 3); break;
        case 2: obj.digitNumbers(digits, 6, 3); break;
        case 3: obj.bothCases(); break;
        default: cout << "Invalid choice!\n";
    }

    return 0;
}
