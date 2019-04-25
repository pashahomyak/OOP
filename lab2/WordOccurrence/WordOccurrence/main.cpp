#include "pch.h"
#include "functions.h"

using namespace std;

int main()
{
	map<string, int> wordOccurrence;
	string word;
	vector<string> inputWords;

	while (cin >> word) {
		inputWords.push_back(word);
	}

	wordOccurrence = wordOccurrenceProcess(inputWords);

	PrintMap(wordOccurrence);
}