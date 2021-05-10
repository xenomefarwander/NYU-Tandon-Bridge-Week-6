/* Question 2:
 * A palindrome is a word, which reads the same backward or forward. For example, noon, civic,
 * radar, level, rotor, kayak, reviver, racecar, redder, madam, and refer are all palindromes.
 * a. Implement a function:
 * bool isPalindrome(string str)
 * This function is given a string str containing a word, and returns true if and only if str is
 * a palindrome.
 * b. Write a program that reads a word from the user and announces to the user if it is a
 * palindrome or not.
 * Your program should interact with the user exactly as it shows in the following example:
 * Please enter a word: level
 * level is a palindrome
 *
 * */

#include <iostream>
#include <string>
using namespace std;


bool isPalindrome(string str);

string reverse(string str);

void swap(char& v1, char& v2);

int main() {

    string inputStr;

    cout << "Please enter a word: ";
    cin >> inputStr;

    if(isPalindrome(inputStr))
        cout << inputStr << " is a palindrome" << endl;
    else
        cout << inputStr << " is not a palindrome" << endl;

    return 0;
}

bool isPalindrome(string str){

    bool returnVal;
    string reverseStr;

    reverseStr = reverse(str);
    if (str == reverseStr)
        returnVal = true;
    else
        returnVal = false;

    return returnVal;
}

string reverse(string str){
    int start = 0;
    int end = str.length();

    while (start < end){
        end -= 1;
        swap(str[start], str[end]);
        start += 1;
    }

    return str;
}


void swap(char& v1, char& v2){

    char temp = v1;
    v1 = v2;
    v2 = temp;
}