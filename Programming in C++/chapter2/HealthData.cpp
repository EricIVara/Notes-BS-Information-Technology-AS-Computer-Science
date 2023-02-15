#include <iostream>
using namespace std;

int main() {
   int userAgeYears;
   int userAgeDays;
   int userAgeMinutes;
   int totalHeartbeats;
   int avgBeatsPerMinute = 72;
   
   cout << "Enter your age in years: ";
   cin  >> userAgeYears;
   
   userAgeDays = userAgeYears * 365;               // Calculate days without leap years
   userAgeDays = userAgeDays + (userAgeYears / 4); // Add days for leap years
   
   cout << "You are " << userAgeDays << " days old." << endl;
   
   userAgeMinutes = userAgeDays * 24 * 60;         // 24 hours/day, 60 minutes/hour
   cout << "You are " << userAgeMinutes << " minutes old." << endl;

   totalHeartbeats = userAgeMinutes * avgBeatsPerMinute;
   cout << "Your heart has beat " << totalHeartbeats << " times." << endl;

   return 0;
}