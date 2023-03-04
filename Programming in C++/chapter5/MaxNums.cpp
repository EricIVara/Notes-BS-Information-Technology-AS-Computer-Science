#include <iostream>
#include <vector>
using namespace std;

int main() {
   const int NUM_VALS = 8;         // Number of elements in vector
   vector<int> userVals(NUM_VALS); // User values
   unsigned int i;                 // Loop index
   int maxVal;                     // Computed max
   
   cout << "Enter " << NUM_VALS << " integer values..." << endl;
   for (i = 0; i < userVals.size(); ++i) {
      cout << "Value: ";
      cin >> userVals.at(i);
   }
   
   // Determine largest (max) number
   maxVal = userVals.at(0);        // Largest so far
   for (i = 0; i < userVals.size(); ++i) {
      if (userVals.at(i) > maxVal) {
         maxVal = userVals.at(i);
      }
   }
   cout << "Max: " << maxVal << endl;
   
   return 0;
}