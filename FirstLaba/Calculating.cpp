#include<iostream>
#include <string>
#include <Windows.h>

using namespace std;

//�������� ��� ����� ������������� ����������
int NumCheck()
{
	int num;

	while (!(cin >> num) || (cin.peek() != '\n'))
	{
		cin.clear();

		while (cin.get() != '\n');
		cout << "����������� ��������� ������, ���������� ������� �����!" << endl;
	}
	return num;
}

//�������� ��� ����� �����
string StringCheck()
{
	string str;
	bool check = true;

	do {
		getline(cin, str);
	} while (str == "");

	return str;
}

//���� ������ � ������
string EnterText()
{
	string text = "";

	cout << "������� �����:" << endl;
	text = StringCheck();
	cout << endl;

	return text;
}

//����� ��������� � ������ � ����� ���������� ����������
void SearchStr(string text)
{
	string strForSearch = "";
	int pos = 0;
	int start = 0;
	int count = 0;
	bool check = true;

	cout << "������� ������ ��� ������." << endl;
	strForSearch = StringCheck();
	cout << endl;

	while (true)
	{
		pos = text.find(strForSearch.c_str(), start);
		if (pos != -1)
		{
			start = pos + strForSearch.size();
			count++;
		}
		else
			break;
	}
	if (count == 0)
	{
		cout << "������ ��������� �� ����������� � ������� ������!" << endl;
	}
	else
	{
		cout << "���������� ����������: " << count << endl;
		cout << endl;
	}
}


void MainFun()
{
	string text = EnterText();
	SearchStr(text);
}