#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
class User {
public:
	User(string login, string password) : login(login), password(password){}

	User() {}

	std::string getPassword()
	{
		return this->password;
	}

	std::string getLogin()
	{
		return this->login;
	}
protected:
	string login;
	string password;
};