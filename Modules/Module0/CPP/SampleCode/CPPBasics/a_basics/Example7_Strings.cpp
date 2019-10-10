/**
 *  Demonstrates creating Strings
 * 
 */

#include <iostream>
#include <string.h>             //!!!Only needed in this program to use the strlen function in line 23
using namespace std;

/**
 * Main Function.
 */
int main() {
    string output = "Hello World 1";                        //std::string if std namespace is not used. Not part of the core C++ language
    char output2[] = "Hello World 2";                       //The traditional way strings are created in C++, using an array of chars. (See the arrays examples for syntax differences from Java)

    cout << output << endl;                                 //Prints the first string
    cout << output2 << endl;                                //Prints the second string

    int outputLength = output.length();                     //Gets the length of the string (similar to Java)
    cout << "output length: " << outputLength << endl;      //Prints the length of output

    int output2Length = strlen(output2);                    //Gets the length of the string/char array
    cout << "output2 length: " << output2Length << endl;    //Prints the length of output
    
    return 0;
}