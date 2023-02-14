#include <iostream>
using namespace std;

int main() {
   int shipWeightPounds;
   int shipCostCents = 0;
   const int FLAT_FEE_CENTS = 75;

   /* Your solution goes here  */
   const int CENTS_PER_POUND = 25;
   cin >> shipWeightPounds;
   shipCostCents = (shipWeightPounds * CENTS_PER_POUND) + FLAT_FEE_CENTS;

   cout << "Weight(lb): " << shipWeightPounds;
   cout << ", Flat fee(cents): " << FLAT_FEE_CENTS;
   cout << ", Cents per lb: " << CENTS_PER_POUND;
   cout << ", Shipping cost(cents): " << shipCostCents << endl;

   return 0;
}