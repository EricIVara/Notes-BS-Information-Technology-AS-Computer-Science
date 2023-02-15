#include <iostream>
using namespace std;

int main() {
   int numCoins;
   int numNickels;
   int numDimes;

   numNickels = 5;
   numDimes = 6;

   numCoins = numNickels + numDimes;

   cout << "There are  " << numCoins << " coins" << endl;

   return 0;
}