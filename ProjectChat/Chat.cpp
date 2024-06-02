#include "Chat.h"
int lastPersonNum;
User Chat::getValidUser(std::string log, std::string pas) // �������, ����������� ���� �� ������������ � ������ ������������������� �������������
{
	for (int i = 0; i < size; i++)
	{
		if (userList[i].getLogin() == log)
		{
			if (userList[i].getPassword() == pas)
			{
				userList[i].online_status = true;
				lastPersonNum = i;
				return userList[i];
			}
		}
	}
	User s;//�� ������, ���� ���, ���������� ������ ������
	s.reg("", "");
	return s;
}
void Chat::log(std::string log, std::string pas)
{
	User tmp2 = getValidUser(log, pas);//��������� ������ ��� ��������
	if (tmp2.getLogin() != "")
	{
		currUser = tmp2;
		std::cout << "�� ������� �����!\n";
		logStatus = true;
	}
	else 
	{
		std::cout << "�������� ������\n";
	}
}
void Chat::logout()
{
	std::cout << "�� ������� �����\n";
	currUser.online_status = false;
	userList[lastPersonNum] = currUser;//������ ������ ������ � ������ �������������
	currUser.clearData();
}
void Chat::sendMes(std::string message, User& tmp, std::string dir)
{
	if (dir == "")
	{
		chat += message + "\n";//���������� ��� ������ ����
		std::cout << "��������� ������� ����������\n";
	}
	else {
		for (int i = 0; i < size; i++)
		{
			if (dir == userList[i].getLogin())//�������� ���������(������ ��������� ���������� � ���������� storage[] � ������ Users)
			{
				int j = 0;
				while (tmp.getStorage(j) != "")
				{
					j++;
				}
				std::string result_mes = "��������� �� " + currUser.getLogin() + " ���: " + userList[i].getLogin() + "\n" + "���������: " + message;
				tmp.setStorage(result_mes, j);
				std::cout << "��������� ������� ����������\n";
				break;
			}
			if (dir != userList[i].getLogin() && i == size - 1)
			{
				std::cout << "��� ������ ������������\n";
			}
		}
	}
}
void Chat::show(User& tmp, bool flag)
{
	if (flag == false)//��� ������ ����� ��������� ������ ����
	{
		std::cout << "����� ���:\n";
		std::cout << chat << std::endl;
	}
	else {//� �����, ��������, ���� �� � ��������� ��� ������������, ����� �� ������ ���������, ������� ���/�� ��������, �������� �����(���� �������)
		std::cout << "���� ���������:\n";
		if (tmp.getStorage(0) == "")
		{
			return;
		}
		for (int i = 0; i < 2000; i++)
		{
			if (tmp.getStorage(i).find(currUser.getLogin())&& tmp.getStorage(i)!="")
			{
				std::cout << tmp.getStorage(i).find(currUser.getLogin()) << std::endl;
			}
			else if (tmp.getStorage(i) =="")
			{
				return;
			}
		}
	}
}
void Chat::showListOfUsers()//����� ���� ������������� � �� ������ ����� ������
{
	std::cout << "������ �������������:\n";
	for (int i = 0; i < size; i++)
	{
		std::cout << "��� ������������: " << userList[i].getLogin();
		if (userList[i].online_status == false)
			std::cout << "������: Offline\n";
		else
			std::cout << "������: Online\n";
	}
}