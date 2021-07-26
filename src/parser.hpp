#include <string>
#include <vector>

// Function to turn equation given as string into 
// a vector of strings representing postfix
std::vector<char> stringToPostfix(std::string equation);

// Function to evaluate vector containing postfix
double evalPostfix(std::vector<char> postVec, double x, double y, double z);
