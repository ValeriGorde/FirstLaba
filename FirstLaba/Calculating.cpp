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

string EnterStr()
{
	string str = "";

	do
	{
		getline(cin, str);
	} while (str == "");

	return str;
}

//Проверка для ввода строк
string StringCheck()
{
	string str;
	bool check = true;
	char ch = 0;
	string buffer = "\0";
	bool firstTry = true;

	while (true) {
		getline(cin, buffer);
		if (buffer != "\0")
			str = str + buffer + "\n";
		else {
			if (str.size() == false) {
				if (firstTry == true)
					firstTry = false;
				else {
					SetConsoleCP(866);
					cout << "Вы не ввели текст. Пожалуйста, попробуйте еще раз." << endl;
					cout << "Введите текст:" << endl;
					cout << "Чтобы завершить ввод текста, нажмите Enter дважды." << endl;
					SetConsoleCP(1251);
				}
			}
			else
				break;
		}
	}
	return str;
}

//Поиск подстроки в строке и вывод количество повторений
int SearchStr(string text, string enterStr)
{
	int pos = 0;
	int start = 0;
	int count = 0;
	bool check = true;
	string buffer = "\0";

	while (true)
	{
		pos = text.find(enterStr.c_str(), start);
		if (pos != -1)
		{
			start = pos + enterStr.size();
			count++;
		}
		else
			break;
	}
	if (count == 0)
	{
		cout << "Данная подстрока не встречается в ведённом тексте!" << endl;
	}
	return count;
}


