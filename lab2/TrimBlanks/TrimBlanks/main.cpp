#include "pch.h"
#include <iostream>
#include <string>

#include "TrimBlanks.h";

using namespace std;

int main()
{
	string inputString;

	getline(cin, inputString);

	string outputString = TrimBlanks(inputString);

	cout << outputString;
}
