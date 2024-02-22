#include <iostream>
#include <string>
using namespace std;

int main() {
   string firstString;
   string secondString;

   firstString = "rabbits";
   secondString = "capes";

   /* Your solution goes here  */
   if (firstString > secondString) {
      cout << secondString << " " << firstString << endl;
   } else {
      cout << firstString << " " << secondString << endl;
   }
   
   return 0;
}