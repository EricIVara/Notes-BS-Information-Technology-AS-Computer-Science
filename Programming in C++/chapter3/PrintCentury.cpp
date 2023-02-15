#include <iostream>
using namespace std;

int main() {
   int givenYear;

   cin >> givenYear;

   if (givenYear >= 2101) {
      cout << "Distant future";
   }
   else if (givenYear >= 2001) {
      cout << "21st century";
   }
   else if (givenYear >= 1901) {
      cout << "20th century";
   }
   else {
      cout << "Long ago";
   }
   
   return 0;
}