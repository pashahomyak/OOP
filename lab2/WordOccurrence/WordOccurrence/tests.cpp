#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "../../catch2/catch.hpp"

#include "functions.h";

using namespace std;

TEST_CASE("many words")
{
	CHECK(wordOccurrenceProcess(vector<string>({ "hello","hello","hello","world!","world" })) == map<string, int>({ {"hello", 3},{"world", 1},{"world!", 1} }));
}

TEST_CASE("empty Input")
{
	CHECK(wordOccurrenceProcess(vector<string>({})) == map<string, int>({}));
}

TEST_CASE("one word")
{
	CHECK(wordOccurrenceProcess(vector<string>({ "hello" })) == map<string, int>({ {"hello", 1} }));
}

TEST_CASE("case infinitive")
{
	CHECK(wordOccurrenceProcess(vector<string>({ "hello", "Hello" })) == map<string, int>({ {"hello", 1}, {"Hello", 1} }));
}

TEST_CASE("numerical character")
{
	CHECK(wordOccurrenceProcess(vector<string>({ "1", "10", "-2" })) == map<string, int>({ {"-2", 1 }, {"1", 1}, {"10", 1} }));
}