#include <iostream>
using namespace std;

void PrintPizzaVolume(double pizzaDiameter, double pizzaHeight) {
   double pizzaRadius;
   double pizzaArea;
   double pizzaVolume;
   double piVal = 3.14159265;

   pizzaRadius = pizzaDiameter / 2.0;
   pizzaArea = piVal * pizzaRadius * pizzaRadius;
   pizzaVolume = pizzaArea * pizzaHeight;
   cout << pizzaDiameter << " x " << pizzaHeight << " inch pizza is ";
   cout << pizzaVolume << " inches cubed." << endl;
}

int main() {
   PrintPizzaVolume(12.0, 0.3);
   PrintPizzaVolume(12.0, 0.8);
   PrintPizzaVolume(16.0, 0.8);
   return 0;
}