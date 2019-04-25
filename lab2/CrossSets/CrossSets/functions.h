#pragma once

#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <algorithm>

int CalculateNumericalSum(int num);
std::set<int> FillSetOfNumDivisibleBySumOfDigits(int N);
std::set<int> FillSetOfNumWhichSumOfDigitsIsEven(int N);
std::set<int> CrossSet(std::set<int>const&set1, std::set<int>const&set2);
void PrintSet(std::set<int>const& resultSet);
