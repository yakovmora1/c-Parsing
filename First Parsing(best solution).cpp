#include "stdafx.h"
#include <iostream>

#include <map>
#include <string>
using namespace std;

void printOperation(string sec1, string sec2, char operat)
{

	int num1, num2;
	num1 = stoi(sec1);
	num2 = stoi(sec2);
	switch (operat)
	{
	case '+':
		cout << num1 + num2;
		break;
	case '-':
		cout << num1 - num2;
		break;
	case '*':
		cout << num1*num2;
		break;
	case '/':
		double ans =(double) num1 / num2;
		cout << ans;
		break;
	}

}


int main(int argc, char *argv[]) {
	void printOperation(string sec1, string sec2, char operat);
	string a;
	cin >> a;
	string section1;
	string section2;
	char operat;
	for (int i = 0; i<a.length(); ++i){
		if (int(a.at(i))>=42&&int(a.at(i))<=47){
			operat = a.at(i);
			section1 = a.substr(0, i);
			section2 = a.substr(i+1 , a.length());
			break;
		}
	}
	cout << section1 << "\n";
	cout << section2 << "\n";
	printOperation(section1, section2, operat);
	return(0);
}

