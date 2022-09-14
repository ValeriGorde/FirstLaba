#include <fstream>
#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>

#include "Calculating.h"
#include "Menu.h"

enum FileOrKey
{
	firstChoice = 1, secondChoice
};

using namespace std;

//�������� ���� ��� ��������!!!!!
//bool CheckFilePath(string path)
//{
//	bool isExist = false;
//	fstream file(path);
//
//	if (file.is_open())
//	{
//		isExist = true;
//	}
//	file.close();
//
//	return isExist;
//
//}

void OpenFromFile()
{
	string path = "";
	string str = "";
	int result = 0;
	bool check = true;

	while (check)
	{
		cout << endl << "������� ���� � �����!" << endl;

		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);

		fstream file(path);

		int size = file.tellg();

		if (file.peek() == EOF)
		{
			cout << "���� ������!" << endl;

		}

		else if (file.is_open())
		{
			while (getline(file, str))
			{
				cout << endl << "������ � �����: " << endl;
				cout << str << endl;
				cout << endl;
			}
			result = SearchStr(str);
			check = false;
		}

		else
		{
			cout << "����� �� ����������!" << endl;
		}
		file.close();
	}


}

//bool FileIsExist(string path) 
//{
//	bool isExist = false;
//	fstream file(path.c_str());
//
//	if (file.is_open())
//	{
//		isExist = true;
//	}
//	file.close();
//
//	return isExist;
//}


bool FileNotEmpty(string path)
{
	bool isExist = false;
	fstream file(path.c_str());

	if (!(file.peek() == EOF))
	{
		cout << "���� �� ������!" << endl;
		cout << endl;
		isExist = true;
	}
	file.close();

	return isExist;
}

//���������� ��������� � ����
void SaveInFile(int result)
{
	string pathSave = "";
	bool check = true;

	while (check)
	{
		cout << "���� ��������� ���������?" << endl;

		cin >> pathSave;

		fstream file;
		file.open(pathSave);


		if (file.is_open())
		{
			if (FileNotEmpty(pathSave)) //���� ���� �� ����
			{
				int variant = 0;

				cout << "�������� ���������� ��������: " << endl;
				cout << "1. ������� ���� � ������� �����." << endl;
				cout << "2. ������������ ����." << endl;
				variant = NumCheck();

				switch (variant)
				{
				case firstChoice:
				{
					check = true;
					break;
				}
				case secondChoice:
				{
					check = false;
					break;
				}
				default: 
				{
					cout << "�� ����� �������� ��������, ���������� ��� ���!" << endl;
				}
				}
			}
			else
			{
				file << "���������� ���������� ��������� � ������: ";
				file << result;
				cout << endl << "���������� ������ �������!" << endl;
				cout << endl;
				check = false;
			}
		}
		else cout << "������!" << endl;
	}


}




void ReWriteInfo() {}
void WriteInfoInFile() {}


