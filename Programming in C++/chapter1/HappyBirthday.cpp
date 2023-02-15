/*
  In this assignment your robot willDraw a birthday cake for your child.
  Produce the program that edits, compiles and executes the below tasks:
  - Display the words “Happy Birthday.”
  - Display your child’s age by entering both your child’s year of birth
    and the current year as inputs. You will need your program to deduct
    your child’s year of birth from the current year and then to display
    the output. For example, 2016 minus 2010 is six. Note: The output to
    the last program is an integer.
  
*/

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