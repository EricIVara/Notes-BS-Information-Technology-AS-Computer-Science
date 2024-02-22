#include <iostream>
using namespace std;

int main() {
  int currPower;
  char userChar;
 
  currPower = 2;
  userChar = 'y';
 
  while (userChar == 'y') {
     cout << currPower << endl;
     currPower = currPower * 2;
     cin >> userChar;
  }
 
  cout << "Done" << endl;
 
  return 0;
}