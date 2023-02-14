#include <iostream>
#include <cmath>
using namespace std;
 
int main() {
   double sideSquare;
   double areaSquare = 49.0;
 
   sideSquare = sqrt(areaSquare);

   cout << "Square root of " << areaSquare
        << " is " << sideSquare << endl;

   return 0;
}