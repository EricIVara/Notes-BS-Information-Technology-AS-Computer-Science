#include <iostream>
using namespace std;

int main() {
  int hotelRate;
  int userAge;
 
  hotelRate = 155;

  cout << "Enter age: ";
  cin >> userAge;
 
  if (userAge > 65) {
     hotelRate = hotelRate - 20;
  }
 
  cout << "Your hotel rate: ";
  cout << hotelRate << endl;
 
  return 0;
}