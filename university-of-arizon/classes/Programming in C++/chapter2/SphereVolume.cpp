#include <iostream>
using namespace std;

/*

    Given sphereRadius and piVal, compute the volume of a sphere and assign sphereVolume
    with the result. Use (4.0 / 3.0) to perform floating-point division, instead of
    (4 / 3) which performs integer division.

    Volume of sphere = (4.0 / 3.0) π r3 (Hint: r3 can be computed using *)

*/

int main() {
   double piVal = 3.14159;
   double sphereVolume;
   double sphereRadius;

   cin >> sphereRadius;

   sphereVolume = (4.0 / 3.0) * piVal * (sphereRadius * sphereRadius * sphereRadius);

   cout << sphereVolume << endl;

   return 0;
}