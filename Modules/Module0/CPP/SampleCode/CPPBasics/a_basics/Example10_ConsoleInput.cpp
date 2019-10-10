/**
 *  Demonstrates getting console/keyboard input
 */

#include <iostream>                                                 //Needed for std

using namespace std;                                                //No need to prefix cout, cin, endl, or string with "std::"

/**
 * Main Function.
 */
int main() {
    string name;                                                    //string variable to hold the input
    cout << "Enter your name: ";                                    //Prints a prompt to the user to enter their name
    cin >> name;                                                    //Assigns input to the name variable
    cout << "Hello, " + name + "!" << endl;                         //Print a greeting

    int number;                                                     //int variable to hold the input
    cout << "Enter a number: ";                                     //Prints a prompt to enter the number
    cin >> number;                                                  //Assigns input to the number variable (no typecasting needed here)
    cout << "The number you entered is " << number << endl;         //Prints the number the user entered

    return 0;                                                       //End of main function
}