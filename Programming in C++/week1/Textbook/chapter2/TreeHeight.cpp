#include <iostream>
#include <cmath>
using namespace std;

int main() {
   double x1 = 1.0;
   double y1 = 2.0;
   double x2 = 1.0;
   double y2 = 5.0;
   double pointsDistance = 0.0;

   /* Your solution goes here  */
   pointsDistance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

   cout << "Points distance: " << pointsDistance << endl;

   return 0;
}