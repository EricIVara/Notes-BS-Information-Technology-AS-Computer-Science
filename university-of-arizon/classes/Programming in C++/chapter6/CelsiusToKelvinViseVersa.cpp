#include <iostream>
using namespace std;

double CelsiusToKelvin(double valueCelsius) {
   double valueKelvin;

   valueKelvin = valueCelsius + 273.15;

   return valueKelvin;
}

/* Your solution goes here  */
double KelvinToCelsius(double valueKelvin) {
   double valueCelsius;

   valueCelsius = valueKelvin - 273.15;
   return valueCelsius;
} 

int main() {
   double valueC;
   double valueK;

   valueC = 10.0;
   cout << valueC << " C is " << CelsiusToKelvin(valueC) << " K" << endl;

   valueK = 283.15;
   cout << valueK << "  is " << KelvinToCelsius(valueK) << " C" << endl;

   return 0;
}