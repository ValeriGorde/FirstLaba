#include <iostream>
#include <string>
#include <clocale>
#include <cstdlib>
#include <Windows.h>

#include "Calculating.h"
#include "WorkWithFiles.h"

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
	cout << "������ ��������� ������������ �� ���� ��������� ��������, � ������� ������������ ����� �����������" << endl;
	cout << "���������� �������� �� ��������� �����-���� �� ����� � ������." << endl;
	cout << "�����: �������� �������" << endl;
	cout << "������: 494" << endl;
	cout << "������������ ������ �1" << endl;
	cout << "������� 3" << endl;
	cout << endl;
}

//����� ���� � ���������� ��� � �����
int ChooseInitialData()
{
	int variant = 0;
	int result = 0;
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
			string text = EnterText();
			result = SearchStr(text);
			check = false;
			return result;

		}
		case secondChoice:
		{
			OpenFromFile();
			check = false;
		}
		default:
		{
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
		}
		}
	}

}


void MenuSaveResults(int result)
{
	int variant = 0;
	cout << "��������� ���������� � ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << endl;

	variant = NumCheck();

	switch (variant)
	{
	case yes:
	{
		SaveInFile(result);
		break;
	}
	case no:
	{
		break;
	}
	default:
	{
		cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
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
			return Menu();
		}
		case finish:
		{
			cout << "��������� ���������." << endl;
			check = false;
		}
		default:
		{
			cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
			check = true;
		}
		}
	}


}



