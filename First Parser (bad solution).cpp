#include "stdafx.h"
#include <iostream>

#include <map>
#include <string>
using namespace std;

void printOperation(string sec1, string sec2, int operat)
{

	int num1, num2;
	num1 = stoi(sec1);
	num2 = stoi(sec2);
	switch (operat)
	{
	case 1:
		cout << num1 + num2;
		break;
	case 2:
		cout << num1 - num2;
		break;
	case 3:
		cout << num1*num2;
		break;
	case 4:
		cout << (double)(num1 / num2);
		break;
	}

}


int main(int argc, char *argv[]) {
	void printOperation(string sec1, string sec2, int operat);
	string a;
	cin >> a;
	map <char, int> oper;
	oper['+'] = 1;
	oper['-'] = 2;
	oper['*'] = 3;
	oper['/'] = 4;
	char tav;
	string section1;
	string section2;
	int operat;
	bool flag = false;
	for (int i = 0; i<a.length(); ++i)
	{
		tav = a.at(i);
		if (oper.count(tav)){
			operat = oper[tav];
			flag = true;
		}
		else{
			if (flag){
				section2 += tav;
			}
			else{
				section1 += tav;
			}
		}
	}
	cout << section1 << "\n";
	cout << section2 << "\n";
	printOperation(section1, section2, operat);
	return(0);
}

