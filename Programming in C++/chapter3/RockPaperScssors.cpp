#include <iostream>
using namespace std;

int main() {
    int nextChoice = 2;

    switch(nextChoice) {
        case 0:
            cout << "Rock" << endl;
            break;
        case 1:
            cout << "Paper" << endl;
            break;
        case 2:
            cout << "Scissors" << endl;
            break;
    }
    
    return 0;
}