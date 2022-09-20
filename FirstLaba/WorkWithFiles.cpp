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

//�������� �� ������������� �����
bool ExistFile(string path)
{
	WIN32_FIND_DATA wfd;
	LPCSTR pathLPC = path.c_str();
	HANDLE hfind = ::FindFirstFile(pathLPC, &wfd);
	if (INVALID_HANDLE_VALUE != hfind) {
		::FindClose(hfind);
		return true;
	}
	return false;
}

//�������� �� ������������ �����
bool FileCorrectChecking(string path)
{
	int one = 1, four = 4;
	size_t five = 5;
	LPCSTR name = path.c_str();
	WIN32_FIND_DATAA findData;
	FindFirstFileA(name, &findData);

	size_t found = path.find_last_of("\\");
	size_t point = path.find_last_of(".");
	size_t base = point - found - one;
	string basefilenameStr = path.substr(found + one, base);
	const char* basefilenameChar = basefilenameStr.c_str();

	if (!_strcmpi(basefilenameChar, "con")) {
		cout << endl << "������������ ��� �����." << endl;
		return false;
	}
	if (path.size() < five) {
		cout << endl << "������������ ��� �����. ��������� ������ ���������� ����� ����� ��������" << endl;
		return false;
	}
	if (path.substr(path.size() - four) != ".txt") {
		cout << endl << "������������ ������ �����. ��������� ���� ������� .txt" << endl;
		return false;
	}
	if (findData.dwFileAttributes & FILE_ATTRIBUTE_READONLY)
	{
		cout << endl << "���� �������� ������ ��� ������." << endl;
		return false;
	}
	if (!ExistFile(path)) {
		cout << endl << "����� �� ���������� ���� �� ����������" << endl;
		return false;
	}
	return true;
}

//�������� �� ������� �����
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

int OpenFromFile()
{
	string path = "";
	string text = "";
	string str = "";
	int result = 0;
	bool check = true;
	string fullText = "";

	while (check)
	{
		cout << endl << "������� ���� � �����!" << endl;

		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);

		fstream file(path);

		if (FileCorrectChecking(path) == false)
		{
			check = true;
		}
		else if (FileNotEmpty(path) == false) //���� ���� �� ����
		{
			cout << "���� ������!" << endl;
			check = true;
		}
		else
		{
			cout << endl << "������ � �����: " << endl;
			while (getline(file, text))
			{
				fullText += text + ' ';
				cout << text << endl;
			}
			cout << endl << "������� ������ ��� ������!" << endl;
			str = EnterText();
			result = SearchStr(fullText, str);
			check = false;

			file.close();
		}
	}
	return result;
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
		/*file.open(pathSave);*/

		if (FileCorrectChecking(pathSave) == true)
		{
			check = false;
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
				}
			}
			if (check == false)
			{
				file.open(pathSave);
				file << "The number of repetitions of a substring in a string: ";
				file << result;
				cout << endl << "���������� ������ �������!" << endl;
				cout << endl;
				check = false;

				file.close();
			}
		}
	}
}


