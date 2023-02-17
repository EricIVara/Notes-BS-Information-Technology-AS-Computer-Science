#include <iostream>
#include <string> // Supports use of "string" data type
using namespace std;

int main() {
    string userInput;

    cout << "Input an abbreviation: " << endl;
    cin >> userInput;

    if((userInput == "LOL") || (userInput == "lol")) {
        cout << "laughing out loud" << endl;
    } else if ((userInput == "BFF") || (userInput == "bff")) {
        cout << "best friends forever" << endl;
    } else if ((userInput == "IMHO") || (userInput == "imho")) {
        cout << "in my humble opinion" << endl;
    } else if ((userInput == "TMI") || (userInput == "tmi")) {
        cout << "too much information" << endl;
    } else {
        cout << "Not a valid input" << endl;
    }
    
    return 0;
}