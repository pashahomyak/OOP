#include "pch.h"

#include "functions.h"

using namespace std;

int CalculateNumericalSum(int num)
{
	int sum = 0;

	while (num != 0)
	{
		sum += num % 10;
		num /= 10;
	}

	return sum;
}

set<int> FillSetOfNumDivisibleBySumOfDigits(int N)
{
	set<int> set1;
	for (int i = 1; i <= N; i++)
	{
		if (i % CalculateNumericalSum(i) == 0)
		{
			set1.insert(i);
		}
	}

	return set1;
}

set<int> FillSetOfNumWhichSumOfDigitsIsEven(int N)
{
	set<int> set2;
	for (int i = 1; i <= N; i++)
	{
		if (CalculateNumericalSum(i) % 2 == 0)
		{
			set2.insert(i);
		}
	}

	return set2;
}

set<int> CrossSet(set<int>const&set1, set<int>const&set2)
{
	set<int> intersect;

	set_intersection(set1.begin(), set1.end(), set2.begin(), set2.end(), inserter(intersect, intersect.begin()));

	return intersect;
}

void PrintSet(set<int>const& resultSet)
{
	for (int n : resultSet)
	{
		cout << n << ' ';
	}
}