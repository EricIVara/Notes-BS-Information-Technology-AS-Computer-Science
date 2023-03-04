#include <iostream>
using namespace std;

/* Direct driving distances between cities, in miles */
/* 0: Boston  1: Chicago  2: Los Angeles */

int main() {
   int cityA;                  // Starting city
   int cityB;                  // Destination city
   int DrivingDistances[3][3]; // Driving distances
   
   // Initialize distances array
   DrivingDistances[0][0] = 0;
   DrivingDistances[0][1] = 960;  // Boston-Chicago
   DrivingDistances[0][2] = 2960; // Boston-Los Angeles
   DrivingDistances[1][0] = 960;  // Chicago-Boston
   DrivingDistances[1][1] = 0;
   DrivingDistances[1][2] = 2011; // Chicago-Los Angeles
   DrivingDistances[2][0] = 2960; // Los Angeles-Boston
   DrivingDistances[2][1] = 2011; // Los Angeles-Chicago
   DrivingDistances[2][2] = 0;
   
   cout << "0: Boston  1: Chicago  2: Los Angeles" << endl;
   
   cout << "Enter city pair (Ex: 1 2) -- ";
   cin >> cityA;
   cin >> cityB;
   
   cout << "Distance: " << DrivingDistances[cityA][cityB];
   cout << " miles." << endl;
   
   return 0;
}