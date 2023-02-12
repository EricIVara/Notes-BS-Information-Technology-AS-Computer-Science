#include <iostream>
using namespace std;

int main() {
   int birth_year, current_year, age;

   cout << "Enter your child's year of birth: ";
   cin >> birth_year;
   cout << "Enter the current year: ";
   cin >> current_year;

   age = current_year - birth_year;
   cout << "Happy Birthday!\n";
   cout << "Your child is " << age << " years old." << endl;

   return 0;
}

