#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

#include "functions.h"

using namespace std;

vector<float>ArrayFill(string inputString)
{
	vector<float> numArray;

	if (inputString.size() > 0)
	{
		float num;

		istringstream stringStream(inputString);

		while (stringStream >> num) {
			numArray.push_back(num);
		}
	}
	else
	{
		cout << "You write empty string." << endl;
	}

	return numArray;
}

vector<float>ArrayCalculation(vector<float> numArray)
{
	if (numArray.size() > 0)
	{
		auto minNumber = min_element(numArray.begin(), numArray.end());
		auto maxNumber = max_element(numArray.begin(), numArray.end());

		float factor = 0;
		
		if (*minNumber != 0)
		{
			factor = *maxNumber / *minNumber;
		}
		else {
			return {};
		}

		for (size_t i = 0; i < numArray.size(); i++) {
			numArray[i] = numArray[i] * factor;
		}
	} 

	return numArray;
}

void ArrayPrint(vector<float> numArray)
{
	for (size_t i = 0; i < numArray.size(); i++)
	{
		cout << numArray[i] << " ";
	}
	cout << endl;
}