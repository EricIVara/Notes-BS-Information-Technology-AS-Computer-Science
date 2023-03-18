#ifndef CREATEUSER_H
#define CREATEUSER_H
#include <string>
using namespace std;

// class definition
class CreateUser {
public:

  // constructor
  CreateUser();

  // mutator member functions
  void SetUsername(string username);
  void SetPassword(string password);

  // accessor memeber functions
  string GetUsername() const;
  string GetPassword() const;
  void Print() const;

  // private helper functions
private:
  string username, password;
};

#endif