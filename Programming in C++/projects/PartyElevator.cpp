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
