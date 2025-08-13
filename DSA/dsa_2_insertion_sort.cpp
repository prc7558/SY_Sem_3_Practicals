// Program where player inputs card numbers, the numbers will be sorted using insertion sort
// After sorting, the sorted card numbers are displayed.

#include<iostream>
using namespace std;

void insertionSort(int array[], int n) {
	int i, j, key;
	
	for (i=1; i<n; i++) {
		key = array[i];
		
		for (j=i-1; (j>=0) && (array[j]>key); j--) {
			array[j+1] = array[j];
		}
		array[j+1] = key;
	}
}

void dispArray(int array[], int n) {
	for(int i = 0; i < n; i++) {
		cout << array[i] << " ";
	}
}

int main() {
	int size;
	cout << "Enter Number of Cards: ";
	cin >> size;

	int* cards = new int[size];
	for(int i = 0; i < size; i++) {
		cout << "Enter Card Number " << i + 1 << " : ";
		cin >> cards[i];
	}

	insertionSort(cards, size);

	cout << "\nYour sorted card numbers are: ";
	dispArray(cards, size);

	cout << "\nCongratulations! Your Cards are sorted." << endl;
	delete[] cards;

	return 0;
}