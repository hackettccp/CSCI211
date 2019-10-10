/**
 *  Demonstrates concatenating and appending Strings
 * 
 */

#include <iostream>
using namespace std;

/**
 * Main Function.
 */
int main() {
    string part1 = "Hello";                                                             //std::string if std namespace is not used.
    string part2 = "World!";

    string output = part1 + " " + part2;                                                //Same process as Java for concatenation
    cout << "Value of output (result of concatenation): " + output + "\n" << endl;

    part1 += " ";                                                                       //Same process as Java for appending
    part1 += part2;
    cout << "Value of part1 (result of appending): " + part1 << endl;

    return 0;
}