#include <iostream>
#include <map>
#include <string>

using namespace std;
int main() {

	typedef map <int,string> mapType;
	mapType SMap;
	
	SMap.insert(pair<int,string>(1234,"Amit XYZ"));
	SMap.insert(pair<int, string>(2222, "Rahul"));
	SMap.insert(pair<int, string>(3333, "Shweta"));
	SMap.insert(pair<int, string>(4444, "Aditi"));
	SMap.insert(pair<int, string>(9999, "Pooja"));
	SMap.insert(pair<int, string>(7777, "Ketaki"));
	
	mapType::iterator iter;
	
	cout<<"========Student directory==========\n";
	cout<<"\n Size of SMap = "<<SMap.size()<<"\n";
	for (iter = SMap.begin(); iter != SMap.end(); iter++) {
		cout << iter->first <<": "<< iter->second<<"\n";
	}
	
	int PRN;
	
	cout<<"\nEnter PRN of the student: ";
	cin>>PRN;
	iter = SMap.find(PRN);
	
	if (iter!= SMap.end())
		cout<<PRN <<"'s name is " <<iter->second ;
	else
		cout<<"Key is not populationMap"<<"\n";
	SMap.clear();
	
	return 0;
}
