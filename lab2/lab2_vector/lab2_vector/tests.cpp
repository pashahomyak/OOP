#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include "functions.h";

TEST_CASE("ArrayFill Test")
{
	CHECK(ArrayFill(std::string("0.1 -1.23 2")) == std::vector<float>({ 0.1, -1.23, 2 }));
	CHECK(ArrayFill(std::string("3 6 9")) == std::vector<float>({3, 6, 9}));
	CHECK(ArrayFill(std::string("")) == std::vector<float>({}));
}

TEST_CASE("ArrayCalculation Test")
{
	CHECK(ArrayCalculation(std::vector<float>({ 3, 6, 9 })) == std::vector<float>({ 9,18,27 }));
	CHECK(ArrayCalculation(std::vector<float>({})) == std::vector<float>({}));
	CHECK(ArrayCalculation(std::vector<float>({0,1,2})) == std::vector<float>({}));
	CHECK(ArrayCalculation(std::vector<float>({3.5, -2.5, 2.0})) == std::vector<float>({ -4.9, 3.5, -2.8 }));
}