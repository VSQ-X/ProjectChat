#pragma once
#include <iostream>
#include <string>
class User {
public:
	bool online_status = false; //������ ������������
	void reg(std::string log, std::string pas); //�����������
	std::string getLogin(); //������ ��� ������
	std::string getPassword(); //������ ��� ������
	std::string getStorage(int i = 0)// ������ ��� ������� ���������
	{
		return storage[i];
	}
	void setStorage(std::string mes, int i = 0)// ������ ��� ������� ���������
	{
		storage[i]=mes;
	}
	void clearData();
protected:
	std::string login = "";
	std::string password = "";
	std::string storage[2000] = { "" }; //������ �������� � 10000 ��� �������� ������ ���������
};
extern int size; //������ ��� ������ �������������