#include <iostream>
using namespace std;

// Output GCD of user-input numA and numB

int main() {
   int numA;  // User input
   int numB;  // User input
   
   cout << "Enter first positive integer: ";
   cin  >> numA;
   
   cout << "Enter second positive integer: ";
   cin  >> numB;
   
   while (numA != numB) { // Euclid's algorithm
      if (numB > numA) {
         numB = numB - numA;
      }
      else {
         numA = numA - numB;
      }
   }
   
   cout << "GCD is: " << numA << endl;
   
   return 0;
}