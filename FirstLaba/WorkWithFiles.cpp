#include <fstream>
#include <iostream>
#include <clocale>
#include <string>
#include <Windows.h>
#include "Calculating.h"

using namespace std;


void OpenFromFile() 
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string path = "";
	string str = "";
	cout << endl << "������� ���� � �����!" << endl;

	SetConsoleCP(1251);
	cin >> path;
	SetConsoleCP(866);

	fstream file(path);

	if (file.is_open()) 
	{
		while (getline(file, str))
		{
			cout << endl << "������ � �����: " << endl;
			cout << str << endl;
			cout << endl;
		}
		SearchStr(str);
	}
	else 
	{
		cout << "���� �� ������!" << endl;
	}
	file.close();

}

void SaveInFile() {}
void ReWriteInfo() {}
void WriteInfoInFile() {}


