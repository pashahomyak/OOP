#include "pch.h"

#include "functions.h"

using namespace std;

const string INVALID_PARAMS = "Invalid arguments count\nUsage: CrossSets.exe <decimal number>";

int main(int argc, char* argv[])
{
	set<int> set1;//NumDivisibleBySumOfDigits
	set<int> set2;//NumWhichSumOfDigitsIsEven

	int N;

	if (argc != 2)
	{
		cout << INVALID_PARAMS << endl;
		return 1;
	}

	N = atoi(argv[1]);

	if (N > 0)
	{
		set1 = FillSetOfNumDivisibleBySumOfDigits(N);
		set2 = FillSetOfNumWhichSumOfDigitsIsEven(N);

		set<int> intersect = CrossSet(set1, set2);

		PrintSet(intersect);
	}
	else
	{
		cout << "Invalid input" << endl << "Write number > 0" << endl;
		return 1;
	}
}
