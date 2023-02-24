/*

This program will output a right triangle based on user specified height triangleHeight
and symbol triangleChar.

(1) The given program outputs a fixed-height triangle using a * character. Is modified 
to output a right triangle that instead uses the user-specified triangleChar character.


(2) The first line will have one user-specified character, such as % or *.
Each subsequent line will have one additional user-specified character until the
number in the triangle's base reaches triangleHeight. Output a space after each
user-specified character, including after the line's last user-specified character.


*/

#include <iostream>
using namespace std;

int main() {
   char triangleChar;
   int triangleHeight;

   cout << "Enter a character:" << endl;
   cin >> triangleChar;
   
   cout << "Enter triangle height:" << endl;
   cin >> triangleHeight;
   cout << endl;
      
   for(int i = 0; i < triangleHeight; ++i){
    for(int j = 0; j <= i; ++j){
        cout << triangleChar << " ";
    }
    cout << endl;
   }
   
   return 0;
}