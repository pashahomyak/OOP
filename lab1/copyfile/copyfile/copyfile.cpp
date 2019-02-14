#include "pch.h"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count\n"
			<< "Usage: copyfile.exe <input file> <output file>\n";
		return 1;
	}

	ifstream Fin(argv[1]);

	if (!Fin.is_open())
	{
		cout << "Failed to open " << argv[1] << " for reading\n";
		return 1;
	}

	ofstream Fout(argv[2]);
	if (!Fout.is_open())
	{
		cout << "Failed to open " << argv[2] << " for writing\n";
		return 1;
	}

	char ch;

	while (!Fin.eof())
	{
		if (Fin.get(ch))
		{
			if (!Fout.put(ch))
			{
				cout << "Failed to save data on disk\n";
				return 1;
			}
		}
	}

	return 0;
}

/*
int main(int argc, char* argv[])
{
	ifstream Fin;
	Fin.open(argv[1], ios_base::in);
	ofstream Fout;
	Fout.open(argv[2], ios_base::out);

	if (Fin.is_open())
	{
		while (!Fin.eof())
		{
			string str;
			//getline(Fin, str);
			if (!getline(Fin, str))
			{
				cout << "Failed to read a line from file" << endl;
			}
			else
			{
				Fout << str << endl;
			}
		}
	}
	else
	{
		cout << "Failed to open text.txt for writing" << endl;
	}
	Fin.close();
	Fout.close();
}
*/
