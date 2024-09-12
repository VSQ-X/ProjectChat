//user class
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <map>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#define MESSAGE_LENGTH 500
#define PORT 8000
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
	~User() {}
protected:
	string login;
	string password;
};
