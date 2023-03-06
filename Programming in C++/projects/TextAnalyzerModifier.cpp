#include <iostream>
#include <string>
using namespace std;

int GetNumOfCharacters(const string usrStr) {
    int count = 0;

    for(int i = 0; i < usrStr.size(); ++i) {
        count += 1;
    }

    cout << count << endl;
}

int main() {
    string userString;

    cout << "Enter a sentence or phrase:" << endl;
    cin >> userString;
    cout << "You entered: " << userString << endl;

    GetNumOfCharacters(userString);

    return 0;
}