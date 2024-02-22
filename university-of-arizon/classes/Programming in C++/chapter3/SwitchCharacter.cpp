#include <iostream>
using namespace std;

int main() {
   char origLetter;

   origLetter = 'a';

   /* Your solution goes here  */
   switch (origLetter) {
      case 'a':
         cout << "Alpha\n";
         break;
         
      case 'A':
         cout << "Alpha\n";
         break;
         
      case 'b':
         cout << "Beta\n";
         break;
         
      case 'B':
         cout << "Beta\n";
         break;
         
      default:
         cout << "Unknown\n";
         break;
   }
   return 0;
}