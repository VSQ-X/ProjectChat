#include "Chat.h"
void Chat::registerUser(string login, string password) {
	for (User& user : users)
	{
		if (user.getLogin() == login)
		{
			throw  "not unique login";
		}
	}
	if (login.length() > 60 || password.length() > 60)
	{
		throw 2;
	}
	User* user = new User(login, password);
	users.push_back(*user);
	userIdent[login] = user;
}
auto Chat::loginUser(string login, string password) -> User* {
	if (userIdent.find(login) != userIdent.end() && userIdent[login]->getPassword() == password) {
		return userIdent[login];
	}
	return nullptr;
}

void Chat::lsMessage(User* sender, string recipientLogin) {
	if (userIdent.find(recipientLogin) != userIdent.end()) {
		string message;
		cout << "Enter message: ";
		cin >> message;
		privateMessages[userIdent[recipientLogin]->getLogin()] = sender->getLogin() + " sends private message to " + userIdent[recipientLogin]->getLogin() + ": " + message;
		cout << sender->getLogin() << " sends private message to " << userIdent[recipientLogin]->getLogin() << ": " << message << endl;
	}
	else 
	{
		cout << "User not found!" << std::endl;
	}
}

void Chat::broadcastMessage(User* sender, string message) {
	for (auto& user : users) {
		if (user.getLogin() == sender->getLogin()) {
			publicMessages.push_back(message);
			cout << sender->getLogin() << " sends message to all: " << message << endl;
		}
	}
}

void Chat::logout(User*& currentUser)
{
	if (currentUser != nullptr) {
		cout << "you have logged out of your account\n";
		currentUser = nullptr;
	}
	else {
		cout << "you are not logged in\n";
	}
}

void Chat::showListOfUsers() {
	for (auto& user : users) {
		cout << "Login: " << user.getLogin() <<endl;
	}
}

void Chat::showLsMessage(string log) {
	if (privateMessages.empty()||privateMessages.find(log)==privateMessages.end()) {
		cout << "No messages yet." << endl;
	}
	else {
		cout << "Personal messages:" << endl;
		for (auto& message : privateMessages) {
			cout << message.second << endl;
		}
	}
}

void Chat::showMessageForAll() {
	if (publicMessages.empty()) {
		cout << "No messages yet." << endl;
	}
	else {
		cout << "Public messages:" << endl;
		for (const auto& message : publicMessages) {
			cout << message << endl;
		}
	}
}
