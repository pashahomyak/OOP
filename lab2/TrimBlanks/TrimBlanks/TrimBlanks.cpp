#include "pch.h"
#include <iostream>
#include <string>

#include "TrimBlanks.h";

using namespace std;

string TrimBlanks(string const &str)
{
	size_t first = str.find_first_not_of(' ');
	if (string::npos == first)
	{
		return "";
	}
	size_t last = str.find_last_not_of(' ');

	return str.substr(first, (last - first + 1));
}
