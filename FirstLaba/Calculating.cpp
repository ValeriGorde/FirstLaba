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
	char ch = 0;

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
int SearchStr(string text, string enterStr)
{
	int pos = 0;
	int start = 0;
	int count = 0;
	bool check = true;

	while (true)
	{
		pos = text.find(enterStr.c_str(), start);
		if (pos != -1)
		{
			start = pos + enterStr.size();
			count++;
		}
		else
			break;
	}
	if (count == 0)
	{
		cout << "������ ��������� �� ����������� � ������� ������!" << endl;
	}

	return count;
}


