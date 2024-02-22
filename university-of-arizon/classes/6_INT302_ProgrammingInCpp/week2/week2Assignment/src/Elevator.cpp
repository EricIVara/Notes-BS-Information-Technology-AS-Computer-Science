#include <iostream>
using namespace std;

int main() {
  const int MAX_WEIGHT = 2500;
  int numGuests = 0, ibsPerGuest = 0, currentWeight = 0;

  while (currentWeight < MAX_WEIGHT) {
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
      cout << "Let's go" << endl << endl;
    } else {
      cout << "Current weight: " << currentWeight << endl
           << endl
           << "This elevator is too heavy by " << currentWeight - MAX_WEIGHT + 1
           << " pounds.\nPlease step Off the elevator." << endl;
    }
  }

  return 0;
}