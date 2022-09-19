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

//Прветствие
void Greetings()
{
	cout << "Данная программа представляет из себя текстовый редактор, в котором пользователь имеет возможность" << endl;
	cout << "определить является ли подстрока заданной строкой в тексте." << endl;
	cout << "Автор: Гордеева Валерия" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №1" << endl;
	cout << "Вариант 3" << endl;
	cout << endl;
}

//Выбор ввод с клавиатуры или с файла
int ChooseInitialData()
{
	int variant = 0;
	int result = 0;
	int endNum = 0;
	bool check = true;

	cout << "Выберите откуда будут считываться исходные данные:" << endl;
	cout << "1. С клавиатуры." << endl;
	cout << "2. С файла" << endl;

	while (check)
	{
		variant = NumCheck();

		switch (variant)
		{
		case firstChoice:
		{
			string text = EnterText();
			string str = EnterText();
			endNum = SearchStr(text, str);
			cout << "Количество повторений: " << endNum << endl;
			check = false;
			break;

		}
		case secondChoice:
		{
			endNum = OpenFromFile();
			check = false;
			break;
		}
		default:
		{
			cout << "Вы ввели неверное значение, попробуйте ещё раз!" << endl;
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
	cout << "Сохранить результаты в файл?" << endl;
	cout << "1. Да" << endl;
	cout << "2. Нет" << endl;
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
			cout << "Вы ввели неверное значение, попробуйте ещё раз!" << endl;
		}
		}
	}


}

//Основное меню
void Menu()
{
	int variant = 0;
	bool check = true;
	int result = 0;


	cout << "МЕНЮ" << endl;
	cout << "Выберите нужный пункт:" << endl;
	cout << "1. Начать программу" << endl;
	cout << "2. Вывести информацию о программе и авторе" << endl;
	cout << "3. Провести тестирование" << endl;
	cout << "4. Выйти из программы" << endl;
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
			cout << "Программа завершена." << endl;
			check = false;
			break;
		}
		default:
		{
			cout << "Вы ввели неверное значение, попробуйте ещё раз!" << endl;
			check = true;
			break;
		}
		}
	}


}



