#include <iostream>
using namespace std;

int main() {
   int userNum;

   cin >> userNum;

   /* Your solution goes here  */
   while(userNum > 1){
      userNum /= 2;
      
      cout << userNum << " ";
   }

   cout << endl;

   return 0;
}