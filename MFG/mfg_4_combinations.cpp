#include <iostream>
using namespace std;

class combination {
public:
    long long fact(int n) {
        long long f=1;
        for (int i=1; i<=n; i++) f*=i;
        return f;
    }

    long long nCr(int n, int r) {
        return (fact(n) / (fact(r)*fact(n-r)));
    }

    // Case 1: Choose 3 among 20
    void debateTeams() {
        long long ways = nCr(20,3);
        cout << "\nNumber of different teams of 3 students = " << ways << endl;
    }

    // Case 2: At least 3 women in a club with 7W, 5M
    void clubCommittee() {
        long long case1 = nCr(7,3) * nCr(5,2);
        long long case2 = nCr(7,4) * nCr(5,1);
        long long case3 = nCr(7,5) * nCr(5,0);
        long long total = case1+case2+case3;
        cout << "\nNumber of committees with at least 3 women = " << total << endl
    }

    // Case 3: At least 1 woman & 1 man from 7W,9M
    void facultyCommittee() {
        long long total=0;
        total += nCr(7,1) * nCr(9,4);
        total += nCr(7,2) * nCr(9,3);
        total += nCr(7,3) * nCr(9,2);
        total += nCr(7,4) * nCr(9,1);
        cout << "\nNumber of committees with at least 1 woman & 1 man = " << total << endl;
    }

    // Case 4: Run all at once
    void allCases() {
        debateTeams();
        clubCommittee();
        facultyCommittee();
    }
};

int main() {
    int ch;
    combination obj;

    cout << "Menu:\n";
    cout << "1. Teams of 3 students from 20 (Debate Competition)\n";
    cout << "2. Committee of 5 with at least 3 women (7W,5M)\n";
    cout << "3. Committee of 5 with at least 1 woman & 1 man (7W,9M)\n";
    cout << "4. Run all cases\n";
    cout << "\nEnter choice (1-4): ";
    cin >> ch;

    switch(ch) {
        case 1: obj.debateTeams(); break;
        case 2: obj.clubCommittee(); break;
        case 3: obj.facultyCommittee(); break;
        case 4: obj.allCases(); break;
        default: cout << "Invalid choice!\n";
    }
    
    return 0;
}
