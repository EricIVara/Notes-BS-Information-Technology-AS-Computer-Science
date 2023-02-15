#include <iostream>
using namespace std;

int main() {
   int userAge;
   int insurancePrice;

   cout << "Enter your age: ";
   cin  >> userAge;

   if (userAge < 16) {                 // Age 15 and under
      cout << "Too young." << endl;
      insurancePrice = 0;
   }
   else if (userAge < 25) {            // Age 16 - 24
      insurancePrice = 4800;
   }
   else if (userAge < 40) {            // Age 25 - 39
      insurancePrice = 2350;
   }
   else {                               // Age 40 and up
      insurancePrice = 2100;
   }
   
   cout << "Annual price: $" << insurancePrice << endl;
   
   return 0;
}