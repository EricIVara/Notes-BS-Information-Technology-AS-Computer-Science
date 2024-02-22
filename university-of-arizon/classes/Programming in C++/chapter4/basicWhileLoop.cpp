#include <iostream>
using namespace std;

int main() {
   int userNum;

   userNum = 9;

   while (userNum >= 0) {
      cout << "Body" << endl;
      cin >> userNum;
   }
   cout << "Done." << endl;

   return 0;
}