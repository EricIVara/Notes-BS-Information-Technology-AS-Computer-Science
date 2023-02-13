/*
    Objective:
    A drink costs 2 dollars. A taco costs 4 dollars.
    Given the number of each, compute total cost and
    assign totalCost with the result. Ex: 4 drinks
    and 6 tacos yields totalCost of 32.

*/

#include <iostream>
using namespace std;

int main() {
   int numDrinks;
   int numTacos;
   int totalCost;

   cin >> numDrinks;
   cin >> numTacos;

   /* Your solution goes here  */
   totalCost = (numDrinks * 2) + (numTacos * 4);

   cout << "Total cost: " << totalCost << endl;

   return 0;
}