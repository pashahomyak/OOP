#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

const string INVALID_PARAMS = "Invalid arguments count\nUsage: dec2bin.exe <decimal number>";
const string INVALID_INPUT = "Invalid decimal number\nWrite integer 0 < number < 2^32 - 1";

int main(int argc, char* argv[])
{
	if (argc != 2)
	{
		cout << INVALID_PARAMS << endl;
		return 1;
	}
	
	char *sign = argv[1];

	if (sign[0] == '-')
	{
		cout << INVALID_INPUT << endl;
		return 1;
	}

	istringstream stringStream(argv[1]);
	string str = stringStream.str();
	unsigned int num;

	try
	{
		num = stoul(str);
	}
	catch (out_of_range)
	{
		cout << INVALID_INPUT << endl;
		return 1;
	}
	catch (invalid_argument)
	{
		cout << INVALID_INPUT << endl;
		return 1;
	}

	if (num == 0)
	{
		cout << "0" << endl;
		return 0;
	}

	int integerPartOfNum, fractionalPartOfNum;
	string binaryRes;

	while (num != 0)
	{
		integerPartOfNum = num / 2;
		fractionalPartOfNum = num % 2;
		binaryRes += to_string(fractionalPartOfNum);
		num = integerPartOfNum;
	}

	for (int i = binaryRes.length() - 1; i >= 0; i--)
	{
		cout << binaryRes[i];
	}
	cout << endl;
}