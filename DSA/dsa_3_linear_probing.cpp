// Hash Techniques - Linear Probing
#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

int main() {
    int i, j, servers, requests, ip, hashVal;
    string ipStr; size_t lastDot;

    cout << "Enter Total Number of Servers: ";
    cin >> servers;
    int hashTable[servers];

    for (i = 0; i < servers; i++)
        hashTable[i] = -1;  //Initialisation

    do {
        cout << "Enter number of requests: ";
        cin >> requests;
    } while (requests > servers);
    cout << endl;  //Prevent Hash_Table overflow

    for (i = 0; i < requests; i++) {
    	do {
        	cout << "Enter IPv4 address " << i + 1 << ": ";
        	cin >> ipStr;
        	lastDot = ipStr.find_last_of('.');
    } while (lastDot == string::npos); //Partially Valid address
    
        ip = stoi(ipStr.substr(lastDot + 1)); //sub_str to int
        hashVal = ip % servers;	//Division Method

        for (j = 0; j < servers; j++) {
            if (hashTable[hashVal] == -1) {
                hashTable[hashVal] = ip;  //Fill Hash_Table
                break;
            } else
                hashVal = (hashVal+1) % servers; //Collision Resolution
        }
    }
	
    for (i = 0; i < servers; i++) {	//Display Hash Output
        cout << "\nServer " << setw(2) << i + 1 << " is handling ";
        if (hashTable[i] != -1)
            cout << setw(3) << fixed << hashTable[i] << " request";
        else
            cout << " no request";
    }

    return 0;
}