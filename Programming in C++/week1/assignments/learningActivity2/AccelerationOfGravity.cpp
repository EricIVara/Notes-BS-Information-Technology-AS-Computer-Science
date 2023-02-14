#include <iostream>
using namespace std;

int main() {
   double G = 6.673e-11;
   double M = 5.98e24;
   double accelGravity;
   double distCenter;

   distCenter = 6.38e6;

   /* Your solution goes here  */
   accelGravity = (G * M) / (distCenter * distCenter);   // (G * M) / (d^2)

   cout << "accelGravity: " << accelGravity << endl;

   return 0;
}