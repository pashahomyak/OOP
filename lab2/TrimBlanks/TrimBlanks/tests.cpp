#include "pch.h"
#include "TrimBlanks.h";

TEST_CASE("TrimBlanks test")
{
	CHECK(TrimBlanks("") == "");
	CHECK(TrimBlanks("Hello") == "Hello");
	CHECK(TrimBlanks("   Hello") == "Hello");
	CHECK(TrimBlanks("Hello   ") == "Hello");
	CHECK(TrimBlanks("    Hello   ") == "Hello");
	CHECK(TrimBlanks("    ") == "");
	CHECK(TrimBlanks("A") == "A");
	CHECK(TrimBlanks("      Hello    World   !   ") == "Hello    World   !");
}