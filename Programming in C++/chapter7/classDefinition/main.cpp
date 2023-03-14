#include "ClassDefinition.h"
#include <iostream>
using namespace std;

int main() {
  Restaurant favLunchPlace;
  Restaurant favDinnerPlace;

  favLunchPlace.SetName("In N' Out");
  favLunchPlace.SetRating(5);

  favDinnerPlace.SetName("Chick-fil-A");
  favDinnerPlace.SetRating(5);

  cout << "My favorite Resauant is: " << endl;
  favLunchPlace.Print();
  favDinnerPlace.Print();

  return 0;
}