#include <string>
#include <iostream>

#include "Calculating.h"
#include "WorkWithFiles.h"


bool TestingBaseFunction(string str) 
{
	int one = 1;
	int two = 2;
	int three = 3;
	int four = 4;

	//Вызов функции поиска подстроки в строке
	int coutSearchFirst = SearchStr(str, "20");
	int coutSearchSecond = SearchStr(str, "мне");
	int coutSearchThird = SearchStr(str, "закончила");
	int coutSearchForth= SearchStr(str, "лет");
	int coutSearchFifth = SearchStr(str, ".");

	//Показатели успешности тестов
	bool countFirstResult = false;
	bool countSecondResult = false;
	bool countThirdResult = false;
	bool countFourthResult = false;
	bool countFifthResult = false;

	if (coutSearchFirst == four)
		countFirstResult = true;
	else
		cout << "Тестирование №1 провалено." << endl;
	if (coutSearchSecond == two)
		countSecondResult = true;
	else
		cout << "Тестирование №2 провалено." << endl;
	if (coutSearchThird == one)
		countThirdResult = true;
	else
		cout << "Тестирование №3 провалено." << endl;
	if (coutSearchForth == two)
		countFourthResult = true;
	else
		cout << "Тестирование №4 провалено." << endl;
	if (coutSearchFifth == three)
		countFifthResult = true;
	else
		cout << "Тестирование №5 провалено." << endl;

	if (countFirstResult && countSecondResult && countThirdResult && countFourthResult && countFifthResult)
		return true;
	else
		return false;
}

void TestingResults() 
{
	string strForCheck = "В 2021 году мне было 20 лет. I was 20 years old in 2021. Когда мне было 17 лет, я закончила школу.";

	if ((TestingBaseFunction(strForCheck)) == true)
		cout << "Тестирование прошло успешно" << endl << endl;
	else
		cout << "Тестирование провалено" << endl << endl;
}