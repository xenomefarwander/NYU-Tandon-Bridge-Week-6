/*Question 6:
Write a program that reads in a line of text and outputs the line with all the digits in all integer
numbers replaced with 'x'.
Please enter a line of text:
My userID is john17 and my 4 digit pin is 1234 which is secret
My userID is john17 and my x digit pin is xxxx which is secret
Notes:
1. If a digits is part of a word, then the digit is not changed to an 'x'. For example, john17 is
NOT changed to johnxx.
2. You may assume that the text entered by the user will contain only letters (upper case or
lower case), digits and spaces.
3. Think how to break down your implementation to functions.
 */

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 256;

void getString(char userString[], int& arrSize);
/* Gets a string from the user and stores into a C-string. arrSize is updated to the logical
 * size of the C-string (not the size in memory) */

void printWithNoSensitiveDigits(char userString[], int arrSize);
/* Takes a user string and prints and hides numbers unless they are attached to a word
 * (i.e. connected to alphabetical characters) */

bool testWord(char str[], int strLength);
/* Tests a C-string and returns true if any alphabetical characters encountered */

int main() {
    char userString[ARRAY_SIZE];
    int userStringSize = 256;

    cout << "Please enter a line of text:" << endl;
    getString(userString, userStringSize);
    printWithNoSensitiveDigits(userString, userStringSize);

    return 0;
}

void getString(char userString[], int& arrSize){
    using namespace std;

    char nextChar;
    cin.get(nextChar);
    int index = 0;
    arrSize = 255; //  Prevents overflow from user
    while (index < arrSize && nextChar != '\n'){
        userString[index] = nextChar;
        index++;
        cin.get(nextChar);
    }
    userString[index] = '\0';
    arrSize = index + 1;
}

void printWithNoSensitiveDigits(char userString[], int arrSize){
    using namespace std;

    char testString[ARRAY_SIZE];

    int i = 0;
    int j = 0;
    int strLength;
    bool isWord;

    while (i < arrSize){
        // Build testString until one of following character is encountered
        if (userString[i] != ' '
        && userString[i] != '/'
        && userString[i] != '-'
        && userString[i] != '.'
        && userString[i] != '\0') {
            testString[j] = userString[i];
            j++;
        }
        else {
            // Test for alphabetical content
            strLength = j;
            isWord = testWord(testString, strLength);

            // Print the string as is if it contains at least 1 alphabetical character
            if (isWord) {
                for (int k = 0; k < strLength; k++) {
                    cout << testString[k];
                }
            }
            // Blackout if there no alphabetical characters
            else {
                for (int k = 0; k < strLength; k++){
                    cout << "x";
                }
            }

            // Print the space or special character if not the null character
            if (userString[i] != '\0')
                cout << userString[i];

            // Reset j to 0 (i.e. start a new word)
            j = 0;
        }
        i++;
    }
    cout << endl;
}

bool testWord(char str[], int strLength){
    using namespace std;

    for (int i = 0; i < strLength; i++) {
        if (isalpha(str[i])){
            return true;
        }
    }
    return false;

}

