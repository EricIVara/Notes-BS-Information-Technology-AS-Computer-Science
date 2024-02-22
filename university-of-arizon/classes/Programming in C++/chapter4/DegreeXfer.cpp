#include <iostream>
using namespace std;

int main() {
   int currC;
   double equivalentF;
   
   for (currC = -10; currC <= 40; currC += 5) {
      equivalentF =  (currC * 9.0 / 5.0) + 32.0;

      cout << currC << " C is ";
      cout << equivalentF << " F";
      cout << endl;
   }
   
   return 0;
}