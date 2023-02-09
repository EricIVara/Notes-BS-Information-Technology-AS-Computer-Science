#include <iostream>
using namespace std;

int main() {
   int dogYears;
   int humanYears;
   
   cin  >> dogYears;
   
   humanYears = 7 * dogYears;
   cout << "A " << dogYears << " year old dog is about a ";
   cout << humanYears << " year old human." << endl;
   
   return 0;
}
