#include <iostream>
using namespace std;

int main() {
   int   stepsWalked;
   const double FEET_PER_STEP = 2.5;               // Typical adult
   const int    FEET_PER_MILE = 5280;
   const double STEPS_PER_MINUTE = 70.0;           // Typical adult
   const double CALORIES_PER_MINUTE_WALKING = 3.5; // Typical adult
   double minutesTotal;
   double caloriesTotal;
   double milesWalked;

   cout << "Enter number of steps walked: ";
   cin >> stepsWalked;

   milesWalked = stepsWalked * FEET_PER_STEP * (1.0 / FEET_PER_MILE);
   cout << "Miles walked: " << milesWalked << endl;

   minutesTotal = stepsWalked / STEPS_PER_MINUTE;
   caloriesTotal = minutesTotal * CALORIES_PER_MINUTE_WALKING;
   cout << "Calories: " << caloriesTotal << endl;

   return 0;
}