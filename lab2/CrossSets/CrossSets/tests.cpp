#define CATCH_CONFIG_MAIN

#include "../../catch2/catch.hpp"

#include "functions.h"

using namespace std;

TEST_CASE("Calculate numerical sum") {
	CHECK(CalculateNumericalSum(0) == 0);
	CHECK(CalculateNumericalSum(10) == 1);
	CHECK(CalculateNumericalSum(5) == 5);
	CHECK(CalculateNumericalSum(43) == 7);
}

TEST_CASE("FillSet1")
{
	CHECK(FillSetOfNumDivisibleBySumOfDigits(45) == set<int>({ 1,2,3,4,5,6,7,8,9,10,12,18,20,21,24,27,30,36,40,42,45 }));
	CHECK(FillSetOfNumDivisibleBySumOfDigits(1) == set<int>({ 1 }));
}

TEST_CASE("FillSet2")
{
	CHECK(FillSetOfNumWhichSumOfDigitsIsEven(45) == set<int>({2,4,6,8,11,13,15,17,19,20,22,24,26,28,31,33,35,37,39,40,42,44}));
	CHECK(FillSetOfNumWhichSumOfDigitsIsEven(1) == set<int>({}));
}

TEST_CASE("CrossSets")
{
	CHECK(CrossSet(FillSetOfNumDivisibleBySumOfDigits(45), FillSetOfNumWhichSumOfDigitsIsEven(45)) == set<int>({2,4,6,8,20,24,40,42}));
	CHECK(CrossSet({ 1,2,3,4,5 }, {1,3,5}) == set<int>({1,3,5}));
	CHECK(CrossSet({ 1 }, {}) == set<int>({}));
	CHECK(CrossSet({}, {}) == set<int>({}));
}
