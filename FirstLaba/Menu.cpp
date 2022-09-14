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

//Прветствие
void Greetings()
{
	cout << "Данная программа представляет из себя текстовый редактор, в котором пользователь имеет возможность" << endl;
	cout << "определить является ли подстрока какой-либо из строк в тексте." << endl;
	cout << "Автор: Гордеева Валерия" << endl;
	cout << "Группа: 494" << endl;
	cout << "Лабораторная работа №1" << endl;
	cout << "Вариант 3" << endl;
	cout << endl;
}

//Выбор ввод с клавиатуры или с файла
void ChooseInitialData()
{
	int variant = 0;

	cout << "Выберите откуда будут считываться исходные данные:" << endl;
	cout << "1. С клавиатуры." << endl;
	cout << "2. С файла" << endl;
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

//Основное меню
void Menu()
{
	int variant = 0;
	bool check = true;


	cout << "МЕНЮ" << endl;
	cout << "Выберите нужный пункт:" << endl;
	cout << "1. Начать программу" << endl;
	cout << "2. Вывести информацию о программе и авторе" << endl;
	cout << "3. Провести тестирование" << endl;
	cout << "4. Выйти из программы" << endl;
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
			cout << "Программа завершена." << endl;
			check = false;
		}
		}
	}


}



bool MenuSaveResults()
{
	int variant = 0;
	cout << "Сохранить результаты в файл?" << endl;
	cout << "1. ДА" << endl;
	cout << "2. НЕТ" << endl;
	cout << endl;

	variant = NumCheck();

	switch (variant)
	{
	case yes: return true;
	case no: return false;
	}

}