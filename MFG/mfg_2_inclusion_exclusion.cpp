#include <iostream>
using namespace std;

class StudentSurvey {
private:
    int T, S, M, inter;

public:
    StudentSurvey(int total, int sports, int music, int both) {
        T = total;
        S = sports;
        M = music;
        inter = both;
    }

    int getUnion() {
        return S + M - inter;
    }

    int getOnlySports() {
        return S - inter;
    }
    
    int getOnlyMusic() {
        return M - inter;
    }

    int getNeither() {
        return T - getUnion();
    }

    void displayResults() {
        int uni = getUnion();
        int only_S = getOnlySports();
        int only_M = getOnlyMusic();
        int neither = getNeither();
		
        cout << "\n--------------- Collected Data ---------------\n";		
		cout << "Number of Students=" << T << ", Sports=" << S << ", Music=" << M << ", Both=" << inter << endl;


        cout << "\n--------------- Survey Results ---------------\n";
        cout << "TOTAL NUMBER of Members in University\t= " << T << endl;
        cout << "Number of Members in ATLEAST 1 Club\t= " << uni << endl;
        cout << "Number of Members in NEITHER Club\t= " << neither << endl;
        cout << "Number of Members in BOTH the Clubs\t= " << inter << endl;
        cout << "Number of Members in SPORTS Club\t= " << S << endl;
        cout << "Number of Members in ONLY SPORTS Club\t= " << only_S << endl;
        cout << "Number of Members in MUSIC Club \t= " << M << endl;
        cout << "Number of Members in ONLY MUSIC Club\t= " << only_M << endl;
    }
};

int main() {
    StudentSurvey survey1(200, 120, 90, 50);
    survey1.displayResults();

    return 0;
}