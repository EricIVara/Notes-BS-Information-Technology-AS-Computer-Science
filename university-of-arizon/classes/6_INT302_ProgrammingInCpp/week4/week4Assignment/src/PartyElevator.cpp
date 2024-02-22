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
#include <vector>
using namespace std;

void scanGuests() {
  const int MAX_WEIGHT = 2500;
  int numGuests = 0, ibsPerGuest = 0, currentWeight = 0;
  vector<int> guestWeights;

  while (currentWeight < MAX_WEIGHT) {
    cout << "Please enter the Number of guests for this elevator trip: ";
    cin >> numGuests;
    cout << endl;

    guestWeights.clear();
    for (int i = 1; i <= numGuests; i++) {
      cout << "Enter the weight of guest " << i << ": ";
      cin >> ibsPerGuest;
      guestWeights.push_back(ibsPerGuest);
    }

    currentWeight = 0;
    for (int weight : guestWeights) {
      currentWeight += weight;
    }

    cout << "Current weight: " << currentWeight << endl << endl;

    if (currentWeight < MAX_WEIGHT) {
      cout << "Let's go up to the party!!!" << endl << endl << "Next party Guests please..." << endl << endl;
    } else {
      cout << "This elevator is too heavy by " << currentWeight - MAX_WEIGHT + 1
           << " pounds.\nPlease step Off the elevator." << endl;
    }
  }
}

// main function, execute program
int main() {

  scanGuests();
  
  return 0;
}
