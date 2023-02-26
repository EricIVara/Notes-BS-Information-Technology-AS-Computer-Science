/*

    You are throwing a giant party at your penthouse in a 25-story building and have invited
    all your family and friends to celebrate New Year’s Eve. You have also requested services
    from a party planning company that will arrange DJs, bartenders, servers, caterers, and a
    band. The main entry to your penthouse is through a standard elevator with a weight
    capacity of 2,500 pounds. Since you do not want your guests taking the stairs to the 25th 
    floor, you need to program your robot to determine if the elevator can support the weight
    of your guests. Applying skills acquired this week, develop, compile, and edit as needed 
    a C++ program that

    Goals
    - calculates the current weight on the occupied elevator,
    - compares the current weight with the maximum weight allowed, and then
    - prints an output stating either “Let's go” or “This elevator is too heavy by X pounds.”

*/

#include <iostream>
using namespace std;

int main() {
  const int MAX_WEIGHT = 2500;
  int numGuests = 0, ibsPerGuest = 0, currentWeight = 0;

  cout << "Number of guests: ";
  cin >> numGuests;
  cout << endl;

  for (int i = 1; i <= numGuests; i++) {
    cout << "Enter the weight of guest " << i << ": ";
    cin >> ibsPerGuest;
    currentWeight += ibsPerGuest;
    cout << "Current weight: " << currentWeight << endl << endl;
  }

  if (currentWeight < MAX_WEIGHT) {
    cout << "Let's go" << endl;
  } else {
    cout << "Current weight: " << currentWeight << endl
         << endl
         << "This elevator is too heavy by " << currentWeight - MAX_WEIGHT + 1
         << " pounds." << endl;
  }

  return 0;
}