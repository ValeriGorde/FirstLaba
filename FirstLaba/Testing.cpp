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

	//����� ������� ������ ��������� � ������
	int coutSearchFirst = SearchStr(str, "20");
	int coutSearchSecond = SearchStr(str, "���");
	int coutSearchThird = SearchStr(str, "���������");
	int coutSearchForth= SearchStr(str, "���");
	int coutSearchFifth = SearchStr(str, ".");

	//���������� ���������� ������
	bool countFirstResult = false;
	bool countSecondResult = false;
	bool countThirdResult = false;
	bool countFourthResult = false;
	bool countFifthResult = false;

	if (coutSearchFirst == four)
		countFirstResult = true;
	else
		cout << "������������ �1 ���������." << endl;
	if (coutSearchSecond == two)
		countSecondResult = true;
	else
		cout << "������������ �2 ���������." << endl;
	if (coutSearchThird == one)
		countThirdResult = true;
	else
		cout << "������������ �3 ���������." << endl;
	if (coutSearchForth == two)
		countFourthResult = true;
	else
		cout << "������������ �4 ���������." << endl;
	if (coutSearchFifth == three)
		countFifthResult = true;
	else
		cout << "������������ �5 ���������." << endl;

	if (countFirstResult && countSecondResult && countThirdResult && countFourthResult && countFifthResult)
		return true;
	else
		return false;
}

void TestingResults() 
{
	string strForCheck = "� 2021 ���� ��� ���� 20 ���. I was 20 years old in 2021. ����� ��� ���� 17 ���, � ��������� �����.";

	if ((TestingBaseFunction(strForCheck)) == true)
		cout << "������������ ������ �������" << endl << endl;
	else
		cout << "������������ ���������" << endl << endl;
}