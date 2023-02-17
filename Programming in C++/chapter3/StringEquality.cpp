
#include <iostream>
#include <string>
using namespace std;

int main() {
   string userWord;

   cout << "Enter a word: ";
   cin  >> userWord;

   if (userWord == "USA") {
      cout << "United States of America";
   }
   else {
      cout << userWord;
   }
   cout << endl;

   return 0;
}