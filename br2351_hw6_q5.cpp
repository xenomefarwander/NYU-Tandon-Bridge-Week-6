/*Question 5:
Write a program that reads a person’s name in the following format:
first name, then middle name or initial, and then last name.
The program then outputs the name in the following format:
Last_Name, First_Name Middle_Initial.
For example, the input
Mary Average User
should produce the output:
User, Mary A.
The input Mary A. User
should also produce the output:
User, Mary A.
Note that your program should work the same and place a period after the middle initial even if
the input did not contain a period.*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string firstName, middleName, lastName;

    cout << "Please enter your first name, middle name (or initial), and last name:" << endl;
    cin >> firstName >> middleName >> lastName;
    cout << lastName << ", " << firstName << " " << middleName[0] << "." << endl;


    return 0;
}
