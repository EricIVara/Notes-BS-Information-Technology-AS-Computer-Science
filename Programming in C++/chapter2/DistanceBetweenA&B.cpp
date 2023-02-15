#include <iostream>
#include <cmath>
using namespace std;

/*

    Determine the distance between point (x1, y1) and point (x2, y2),
    and assign the result to pointsDistance. The calculation is:

    You may declare additional variables.
    Ex: For points (1.0, 2.0) and (1.0, 5.0), pointsDistance is 3.0.

*/

int main() {
   double x1 = 1.0;
   double y1 = 2.0;
   double x2 = 1.0;
   double y2 = 5.0;
   double pointsDistance = 0.0;

   pointsDistance = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2));

   cout << "Points distance: " << pointsDistance << endl;

   return 0;
}