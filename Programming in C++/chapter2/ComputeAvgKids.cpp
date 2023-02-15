#include <iostream>
using namespace std;

int main() {
   int numKidsA;
   int numKidsB;
   int numKidsC;
   int numFamilies;
   double avgKids;

   numKidsA = 1;
   numKidsB = 4;
   numKidsC = 5;
   numFamilies = 3;

   /* Your solution goes here  */
   avgKids = (numKidsA + numKidsB + numKidsC) / static_cast<double>(numFamilies);

   cout << "Average kids per family: " << avgKids << endl;

   return 0;
}