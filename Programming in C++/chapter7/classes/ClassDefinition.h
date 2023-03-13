#ifndef CLASSDEFINITION_H
#define CLASSDEFINITION_H
#include <string>
using namespace std;

// class definition
class Restaurant {
public:
  // mutator inline functions
  void SetName(string restaurantName);
  void SetRating(int userRating);

  // accessor inline functions
  string GetName() const;
  int GetRating() const;
  void Print() const;

  // private helpers
private:
  string name;
  int rating;
};

#endif