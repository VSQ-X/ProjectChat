#include "User.h"
int size = 0; //������ ��� ������ ������������� (���������� ����������)
void User::reg(std::string log, std::string pas)//������
{
	login = log;
	password = pas;
	std::cout << "�� ������� ������������������\n";
}
std::string User::getPassword()//������
{
	return this->password;
}
std::string User::getLogin()//������
{
	return this->login;
}
void User::clearData()// ������� ��� �������� ����� � ������ User, ��� ��������� �����������
{
	login = "";
	password = "";
	online_status = false;
}