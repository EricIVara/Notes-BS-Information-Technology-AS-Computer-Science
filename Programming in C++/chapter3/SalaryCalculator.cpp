#include <iostream>
using namespace std;

int main() {
   int hourlyWage;
   int workHoursPerWeek;
   int workWeeksPerYear;
   int annualSalary;
   int monthlySalary;
   
   cout << "Enter your hourly wage: " << endl;
   cin >> hourlyWage;
   cout << "Enter your work Hours PerWeek: " << endl;
   cin >> workHoursPerWeek;
   cout << "Enter your work Weeks Per Year: " << endl;
   cin >> workWeeksPerYear;

   annualSalary = hourlyWage * workHoursPerWeek * workWeeksPerYear;
   
   cout << "Annual salary is: ";
   cout << annualSalary << endl;

   monthlySalary = annualSalary / 12;
   cout << "Monthly salary is: ";
   cout << monthlySalary << endl;

   return 0;
}
