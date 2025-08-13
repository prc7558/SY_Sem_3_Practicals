#include<iostream>
using namespace std;

class Game {
private:
    int size;
    int* score;

public:
    void swap(int *a, int *b);
    int bubbleSort();
	void dispArray();
	
	Game() {
        size = 0;
        score = nullptr;
    }

    void startGame(int playerNum) {
        cout << "\n\n--- Player " << playerNum << " ---";
        cout << "\nEnter Number of Scores: ";
        cin >> size;

        score = new int[size];
        for(int i = 0; i < size; i++) {
            cout << "Enter Score " << i + 1 << " : ";
            cin >> score[i];
        }

        int levels = bubbleSort();

        cout << "\n\nYour sorted scores are: ";
        dispArray();

        cout << "\nCongratulations! Scores are sorted. You passed " << levels << " levels" << endl;
    }

    ~Game() {
        delete[] score;
    }
};

void Game::swap(int *a, int *b) {
	cout << "\nSwapping " << *a << " with " << *b << ".\tYou leveled up!";
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Game::bubbleSort() {
    int count = 0;
    for(int i = 0; i < size - 1; i++) {
        for(int j = 0; j < size - i - 1; j++) {
            if(score[j] > score[j + 1]) {
                count++;
                swap(&score[j], &score[j + 1]);
            }
        }
    }
    return count;
}

void Game::dispArray() {
    for(int i = 0; i < size; i++) {
        cout << score[i] << " ";
	}
}

int main() {
    int num;
    cout << "Enter number of players: ";
    cin >> num;

    Game* player = new Game[num];

    for(int i = 0; i < num; i++) {
        player[i].startGame(i + 1);
    }

    delete[] player;

    return 0;
}