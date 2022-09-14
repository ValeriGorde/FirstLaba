#include<iostream>
#include <string>
#include <Windows.h>

using namespace std;

//Проверка для ввода целочисленных переменных
int NumCheck()
{
	int num;

	while (!(cin >> num) || (cin.peek() != '\n'))
	{
		cin.clear();

		while (cin.get() != '\n');
		cout << "Неккоректно введенные данные, пожалуйста введите цифру!" << endl;
	}
	return num;
}

//Проверка для ввода строк
string StringCheck()
{
	string str;
	bool check = true;

	do {
		getline(cin, str);
	} while (str == "");

	return str;
}

//Ввод текста в строку
string EnterText()
{
	string text = "";

	cout << "Введите текст:" << endl;
	text = StringCheck();
	cout << endl;

	return text;
}

//Поиск подстроки в строке и вывод количество повторений
void SearchStr(string text)
{
	string strForSearch = "";
	int pos = 0;
	int start = 0;
	int count = 0;
	bool check = true;

	cout << "Введите строку для поиска." << endl;
	strForSearch = StringCheck();
	cout << endl;

	while (true)
	{
		pos = text.find(strForSearch.c_str(), start);
		if (pos != -1)
		{
			start = pos + strForSearch.size();
			count++;
		}
		else
			break;
	}
	if (count == 0)
	{
		cout << "Данная подстрока не встречается в ведённом тексте!" << endl;
	}
	else
	{
		cout << "Количество повторений: " << count << endl;
		cout << endl;
	}
}


void MainFun()
{
	string text = EnterText();
	SearchStr(text);
}