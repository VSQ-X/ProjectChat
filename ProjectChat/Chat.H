#pragma once//класс непосредственно для реализации самого чата
#include "User.h"
class Chat {
private:
	vector<User> users;//вектор для хранения пользователей 
	map<string, User*> userIdent;//идентификация пользователя по паролю и логину
	map<string, string> privateMessages;//хранение личных сообщений пользователей, ключ- имя пользователя, значение- личное сообщение
	vector<string> publicMessages; // вектор лля хранения сообщений для общего чата.
public:
	//реализация функционала чата
	void registerUser(string login, string password);//регистрация пользоватея

	auto loginUser(string login, string password) -> User*;//вход пользователя

	void lsMessage(User* sender, string recipientLogin);//отправка личных сообщений

	void broadcastMessage(User* sender, string message);//отправка сообщений в общий чат

	void logout(User*& currentUser);// выход из аккаунта

	void showListOfUsers();//показ всех зарегистрированных пользователей в чате

	void showLsMessage(string log);//показывает личные сообщения 

	void showMessageForAll();//показывает сообщения в общем чате

	~Chat() {}
};