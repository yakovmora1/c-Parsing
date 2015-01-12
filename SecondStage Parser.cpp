#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
using namespace std;

double returnSum(string sec1, string sec2, char operat)
{
	int num1, num2;
	num1 = stoi(sec1);
	num2 = stoi(sec2);
	switch (operat)
	{
	case '+':
		return( (double) num1 + num2);
		break;
	case '-':
		return((double)num1 - num2);
		break;
	case '*':
		return((double)num1*num2);
		break;
	case '/':
		double ans = (double)num1 / num2;
		return(ans);
		break;
	}

}

	


int main(int argc, char *argv[]) {
	double returnSum(string sec1, string sec2, char operat);
	void vectorValuesSum(vector<string> chars);
	string a;
	cin >> a;
	map <string, int> oper;
	oper["+"] = 1;
	oper["-"] = 2;
	oper["*"] = 3;
	oper["/"] = 4;
	vector<string> chars;
	string temp = "";
	for (int i = 0; i < a.length(); ++i){
		if (oper.count(string(1,a.at(i)))) {
			chars.push_back(temp);
			temp = "";
			chars.push_back(string(1, a.at(i)));
		}
		else {
			temp += a.at(i);
		}
	}
	chars.push_back(temp);
	int specOperIndex = 0;
	double sum;
	ostringstream ssum;
	for (int i = 0; i < chars.size(); ++i) {		
		if (oper.count(chars[i])) {
			if (oper[chars[i]] == 3 || oper[chars[i]] == 4){
				sum = returnSum(chars[i - 1], chars[i+1] , chars[i].at(0));//scum for passing a char
				chars.erase(chars.begin() + i - 1, chars.begin() + i +2);
				ssum << sum;
				chars.insert(chars.begin() +(i-1) , ssum.str());
				ssum.str("");//clear the streamstring
				i=i-1;
			}
            
        
		}
	}

	for (int i = 0; i < chars.size(); ++i) {
		if (oper.count(chars[i])) {
			sum = returnSum(chars[i - 1], chars[i + 1], chars[i].at(0));//scum for passing a char
			chars.erase(chars.begin() + i - 1, chars.begin() + i + 2);
			ssum << sum;
			chars.insert(chars.begin() + (i - 1), ssum.str());
			i = 0;
			ssum.str("");//clear the streamstring
		}
	}

	cout << chars[0];


	return(0);
}

