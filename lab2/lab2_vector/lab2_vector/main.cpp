#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>

#include "functions.h"

using namespace std;

int main()
{
	vector<float> numericArray;
	
	string inputString;
	getline(cin, inputString);

	numericArray = ArrayFill(inputString);
	if (numericArray.size() == 0)
	{
		return 1;
	}
	numericArray = ArrayCalculation(numericArray);
	if (numericArray.size() == 0)
	{
		cout << "You write 0 in inputBuf." << endl;
		return 1;
	}
	sort(numericArray.begin(), numericArray.end());
	ArrayPrint(numericArray);
}