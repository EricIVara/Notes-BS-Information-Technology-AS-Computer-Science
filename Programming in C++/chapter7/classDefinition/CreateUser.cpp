#include "ClassDefinition.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
Restaurant::Restaurant() {
  name = "No Name";
  rating = -1;
}

// mutator inline memeber function definitions
void Restaurant::SetName(string restaurantName) { name = restaurantName; }
void Restaurant::SetRating(int userRating) { rating = userRating; }

// accessor inline member function definitions
string Restaurant::GetName() const { return name; }
int Restaurant::GetRating() const { return rating; }
void Restaurant::Print() const { cout << name << " -- " << rating << endl; }