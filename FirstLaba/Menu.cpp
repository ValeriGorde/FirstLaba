#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <Windows.h>

#include "Calculating.h"
#include "WorkWithFiles.h"
#include "Testing.h"

using namespace std;

enum MenuChoice
{
	redo = 1, info, test, finish
};

enum YesOrNo
{
	yes = 1, no
};

enum FileOrKey
{
	firstChoice = 1, secondChoice
};

//����������
void Greetings()
{
	cout << "������ ��������� ������������ �� ���� ��������� ��������, � ������� ������������" << endl;
	cout << "����� ����������� ���������� �������� �� ��������� �������� ������� � ������." << endl;
	cout << "�����: �������� �������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �1" << endl;
	cout << "������� 3" << endl;
	cout << endl;
}

void SaveOrNot(string& text, string& str)
{
	int variant = 0;
	bool check = true;

	cout << "�� ������ ��������� �������� ������ � ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;

	while (check)
	{
		variant = NumCheck();
		switch (variant)
		{
		case 1:
		{
			SaveInitialInFile(text, str);
			check = false;
			break;
		}
		case 2:
		{
			check = false;
			break;
		}
		default:
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
			break;
		}
	}
}

//����� ���� � ���������� ��� � �����
int ChooseInitialData()
{
	int variant = 0;
	int result = 0;
	int endNum = 0;
	bool check = true;

	cout << "�������� ������ ����� ����������� �������� ������:" << endl;
	cout << "1. � ����������." << endl;
	cout << "2. � �����" << endl;

	while (check)
	{
		variant = NumCheck();

		switch (variant)
		{
		case firstChoice:
		{
			cout << "������� �����:" << endl;
			cout << "����� ��������� ���� ������, ������� Enter ������." << endl << endl;
			string text = StringCheck();

			cout << "������� ��������� ��� ������:" << endl;
			string str = StringCheck();

			SaveOrNot(text, str);

			endNum = SearchStr(text, str);
			cout << "���������� ����������: " << endNum << " ���." << endl << endl;
			check = false;
			break;
		}
		case secondChoice:
		{
			endNum = OpenFromFile();
			cout << "���������� ����������: " << endNum << " ���." << endl << endl;
			check = false;
			break;
		}
		default:
		{
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl << endl;
			break;
		}
		}
	}
	return endNum;
}

void MenuSaveResults(int result)
{
	bool check = true;
	int variant = 0;
	cout << "��������� ���������� � ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << endl;

	while (check)
	{
		variant = NumCheck();

		switch (variant)
		{
		case yes:
		{
			SaveInFile(result);
			check = false;
			cout << endl;
			break;
		}
		case no:
		{
			check = false;
			cout << endl;
			break;
		}
		default:
		{
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
			break;
		}
		}
	}
}

//�������� ����
void Menu()
{
	int variant = 0;
	bool check = true;
	int result = 0;

	cout << "����" << endl;
	cout << "�������� ������ �����:" << endl;
	cout << "1. ������ ���������" << endl;
	cout << "2. ������� ���������� � ��������� � ������" << endl;
	cout << "3. �������� ������������" << endl;
	cout << "4. ����� �� ���������" << endl;
	cout << endl;

	while (check)
	{
		variant = NumCheck();

		switch (variant)
		{
		case redo:
		{
			result = ChooseInitialData();
			MenuSaveResults(result);
			return Menu();
		}

		case info:
		{
			cout << endl;
			Greetings();
			return Menu();
		}
		case test:
		{
			TestingResults();
			return Menu();
		}
		case finish:
		{
			cout << "��������� ���������." << endl;
			check = false;
			break;
		}
		default:
		{
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
			check = true;
			break;
		}
		}
	}
}



