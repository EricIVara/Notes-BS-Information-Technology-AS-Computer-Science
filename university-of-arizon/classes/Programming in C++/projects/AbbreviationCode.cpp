#include <iostream>
#include <string> // Supports use of "string" data type
#include <cctype> // library to use the std::tolower function
using namespace std;

int main() {
  string userInput;

  cout << "Input an abbreviation:" << endl;
  cin >> userInput;

  for (int i = 0; i < userInput.length(); i++) {
    userInput[i] = tolower(userInput[i]);
  }

  if (userInput == "lol") {
    cout << "laughing out loud" << endl;
  } else if (userInput == "bff") {
    cout << "best friends forever" << endl;
  } else if (userInput == "imho") {
    cout << "in my humble opinion" << endl;
  } else if (userInput == "tmi") {
    cout << "too much information" << endl;
  } else if(userInput == "idk") {
     cout << "I don't know" << endl;
  } else {
    cout << "Unknown" << endl;
  }

  return 0;
}