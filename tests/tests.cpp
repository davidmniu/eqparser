#define CATCH_CONFIG_MAIN
#define CATCH_CONFIG_FAST_COMPILE
#include "catch.hpp"
#include "math.h"
#include "../src/parser.hpp"

TEST_CASE("String to Postfix") {
	std::string equation = "3 + 4 * 2 / ( 1 - 5 ) ^ 2 ^ 3";
	std::vector<char> correctOutput = {'3', '4', '2', '*', '1', '5', '-', '2', '3', '^', '^', '/', '+'};
	std::vector<char> output = stringToPostfix(equation);
	REQUIRE(output == correctOutput);
}

TEST_CASE("Evaluate postfix") {
	std::vector<char> postVec = {'3', '4', '2', '*', '1', '5', '-', '2', '3', '^', '^', '/', '+'};
	double output = evalPostfix(postVec, 0, 0, 0);
	double correctOutput = 3 + 4 * 2 / pow(( 1 - 5 ), pow(2, 3));
	double epsilon = 0.00001;
	REQUIRE(abs(output - correctOutput) <= epsilon);
}