#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count" << endl
			 << "Usage: copyfile.exe <input file> <output file>" << endl;
		return 1;
	}

	ifstream inputFile(argv[1]);

	if (!inputFile.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading" << endl;
		return 1;
	}

	ofstream outputFile(argv[2]);
	if (!outputFile.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing" << endl;
		return 1;
	}

	string line;

	while (!inputFile.eof())
	{
		if (getline(inputFile, line))
		{
			outputFile << line << endl;
		}
		else
		{
			cout << "Failed to read data from file" << endl;
		}
	}

	inputFile.close();
	outputFile.close();

	return 0;
}
