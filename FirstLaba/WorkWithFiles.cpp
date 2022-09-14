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

//Засунуть сюда все проверки!!!!!
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
		cout << endl << "Введите путь к файлу!" << endl;

		SetConsoleCP(1251);
		cin >> path;
		SetConsoleCP(866);

		fstream file(path);

		int size = file.tellg();

		if (file.peek() == EOF)
		{
			cout << "Файл пустой!" << endl;

		}

		else if (file.is_open())
		{
			while (getline(file, str))
			{
				cout << endl << "Данные в файле: " << endl;
				cout << str << endl;
				cout << endl;
			}
			result = SearchStr(str);
			check = false;
		}

		else
		{
			cout << "Файла не сущесвтует!" << endl;
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
		cout << "Файл не пустой!" << endl;
		cout << endl;
		isExist = true;
	}
	file.close();

	return isExist;
}

//Сохранение резулатов в файл
void SaveInFile(int result)
{
	string pathSave = "";
	bool check = true;

	while (check)
	{
		cout << "Куда сохранить результат?" << endl;

		cin >> pathSave;

		fstream file;
		file.open(pathSave);


		if (file.is_open())
		{
			if (FileNotEmpty(pathSave)) //если файл НЕ пуст
			{
				int variant = 0;

				cout << "Выберите дальнейшие действия: " << endl;
				cout << "1. Указать путь к другому файлу." << endl;
				cout << "2. Перезаписать файл." << endl;
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
					cout << "Вы ввели неверное значение, попробуйте ещё раз!" << endl;
				}
				}
			}
			else
			{
				file << "Количество повторений подстроки в строке: ";
				file << result;
				cout << endl << "Сохранение прошло успешно!" << endl;
				cout << endl;
				check = false;
			}
		}
		else cout << "Ошибка!" << endl;
	}


}




void ReWriteInfo() {}
void WriteInfoInFile() {}


