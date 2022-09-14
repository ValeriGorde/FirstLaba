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
	key = 1, file
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
void ChooseInitialData()
{
	int variant = 0;

	cout << "�������� ������ ����� ����������� �������� ������:" << endl;
	cout << "1. � ����������." << endl;
	cout << "2. � �����" << endl;
	variant = NumCheck();

	switch (variant)
	{
	case key:
	{
		string text = EnterText();
		SearchStr(text);
		break;

	}
	case file:
	{
		OpenFromFile();
	}

	}
}

//�������� ����
void Menu()
{
	int variant = 0;
	bool check = true;


	cout << "����" << endl;
	cout << "�������� ������ �����:" << endl;
	cout << "1. ������ ���������" << endl;
	cout << "2. ������� ���������� � ��������� � ������" << endl;
	cout << "3. �������� ������������" << endl;
	cout << "4. ����� �� ���������" << endl;
	cout << endl;

	variant = NumCheck();

	while (check)
	{
		switch (variant)
		{
		case redo:
		{
			ChooseInitialData();
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
		}
	}


}



bool MenuSaveResults()
{
	int variant = 0;
	cout << "��������� ���������� � ����?" << endl;
	cout << "1. ��" << endl;
	cout << "2. ���" << endl;
	cout << endl;

	variant = NumCheck();

	switch (variant)
	{
	case yes: return true;
	case no: return false;
	}

}