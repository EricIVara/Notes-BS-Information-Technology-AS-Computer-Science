#include <iostream>
using namespace std;

int main() {
   bool isRed;
   bool isBalloon;

   cin >> isRed;
   cin >> isBalloon;

   /* Your solution goes here  */
   if (isBalloon == true && isRed == false)
      cout << "Balloon" << endl;
   else if(isBalloon == true && isRed == true)
      cout << "Red balloon" << endl;
   else
      cout << "Not a balloon" << endl;
   
   return 0;
}