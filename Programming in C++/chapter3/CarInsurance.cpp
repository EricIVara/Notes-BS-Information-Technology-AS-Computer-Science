#include <iostream>
using namespace std;

int main() {
  int userAge;
  int insurancePrice;
 
  cout << "Enter age: ";
  cin  >> userAge;
 
  if (userAge < 25) {
     insurancePrice = 4800;
  }
  else {
     insurancePrice = 2200;
  }
 
  cout << "Annual price: $";
  cout << insurancePrice << endl;
 
  return 0;
}