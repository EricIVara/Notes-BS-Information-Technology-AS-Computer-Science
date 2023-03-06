#include <iostream>
using namespace std;

void PrintPizzaArea(double pizzaDiameter) {
   double pizzaRadius;
   double pizzaArea;
   double piVal = 3.14159265;

   pizzaRadius = pizzaDiameter / 2.0;
   pizzaArea = piVal * pizzaRadius * pizzaRadius;
   cout << pizzaDiameter << " inch pizza is ";
   cout << pizzaArea << " inches squared." << endl;
}

int main() {
   PrintPizzaArea(12.0);
   PrintPizzaArea(16.0);
   return 0;
}