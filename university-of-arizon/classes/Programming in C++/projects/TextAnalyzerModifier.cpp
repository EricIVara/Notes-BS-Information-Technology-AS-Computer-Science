#include <iostream>
#include <string>
using namespace std;

void OutputWithoutWhitespace(const string usrStr) {
    for(int i = 0; i < usrStr.length(); ++i) {
        if(usrStr.at(i) != ' ' && usrStr.at(i) != '\t') {
            cout << usrStr[i];
        }
    }
}

int GetNumOfCharacters(const string usrStr) {
    int count = 0;

    for(int i = 0; i < usrStr.length(); ++i) {
        count++;
    }

    return count;
}

int main() {
    string userString;

    cout << "Enter a sentence or phrase:" << endl;
    getline(cin, userString);
    cout << endl;
    cout << "You entered: " << userString << endl;
    cout << endl;
    

    int numOfChars = GetNumOfCharacters(userString);
    cout << "Number of characters: " << numOfChars << endl;

    cout << "String with no whitespace: ";
    OutputWithoutWhitespace(userString);
    cout << endl;

    return 0;
}