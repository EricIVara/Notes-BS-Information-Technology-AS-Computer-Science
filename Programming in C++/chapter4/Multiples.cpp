#include <iostream>
using namespace std;

// Outputs 10 15 20 25 30 35 40 45 50

int main() {
   int i;

   for (i = 10; i <= 50; i = i + 5) {
      cout << i << " ";
   }

   cout << endl;

   return 0;
}