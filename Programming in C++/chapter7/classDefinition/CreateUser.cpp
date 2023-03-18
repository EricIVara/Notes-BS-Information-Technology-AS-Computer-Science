#include "CreateUser.h"
#include <iostream>
#include <string>
using namespace std;

// constructor
CreateUser::CreateUser() {
  username = "No Username";
  password = "Password";
}

// mutator inline memeber function definitions
void CreateUser::SetUsername(string username) { username = username; }
void CreateUser::SetPassword(string password) { password = password; }

// accessor inline member function definitions
string CreateUser::GetUsername() const { return username; }
string CreateUser::GetPassword() const { return password; }
void CreateUser::Print() const { cout << username << " -- " << password << endl; }