#include "pch.h"
#include "functions.h"

using namespace std;

map<string, int>wordOccurrenceProcess(vector<string> inputBuf)
{
	map<string, int> wordOccurrence;

	for (string word : inputBuf)
	{
		++wordOccurrence[word];
	}

	return wordOccurrence;
}

void PrintMap(map<string, int> wordMap)
{
	for (auto item : wordMap)
	{
		cout << item.first << ": " << item.second << endl;
	}
}