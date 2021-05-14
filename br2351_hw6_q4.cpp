/* Question 4:
Traditional password entry schemes are susceptible to "shoulder surfing" in which an attacker
watches an unsuspecting user enter their password or PIN number and uses it later to gain
access to the account. One way to combat this problem is with a randomized challenge response
system. In these systems the user enters different information every time, based on a
secret in response to a randomly generated challenge.
Consider the following scheme, in which the password consists of a five-digit PIN number (00000
to 99999). Each digit is assigned a random number that is 1, 2, or 3. The user enters the random
numbers that correspond to their PIN instead of their actual PIN numbers.
For example, consider an actual PIN number of 12345. To authenticate the user would be
presented with a screen such as:
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 3 2 3 1 1 3 2 2 1 3
The user would enter 23113 instead of 12345. This doesn’t divulge the password even if an
attacker intercepts the entry because 23113 could correspond to other PIN numbers, such as
69440 or 70439.
The next time the user logs in, a different sequence of random numbers would be generated,
such as:
PIN: 0 1 2 3 4 5 6 7 8 9
NUM: 1 1 2 3 1 2 2 3 3 3
Write a program to simulate the authentication process. Store an actual 5-digit PIN number in
your program (make one up, and store it as a constant). The program should use an array to
assign random numbers to the digits from 0 to 9. Output the random digits to the screen, input
the response from the user, and output whether or not the user’s response correctly matches
the PIN number. */

#include <iostream>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <cmath>
using namespace std;

void initializeProgram (int cipherCode[], int arrSize);
/* Initializes screen and generates cipher by calling cipherGenerator function*/

void cipherGenerator (int arr[], int arrSize);
/* Generates arrSize number of random integers, range 0-9, and stores them in an array */

void pinEncrypt(const int inputPin[], int outputPin[], const int cipherCode[], int arrSize);
/* Encrypts a pin by matching each digit to the index value in the encoding array.
 * Returns the encoded pin as an integer. ALL THREE ARRAYS SHOULD MATCH IN SIZE */

void getPin(int& input);
/* Reads user's first 5 integers from cin (discards non-numerical items), stored as integer passed as
 * parameter */

bool pinValidator(int inputPin, const int encryptedPin[]);
/* Takes 5-digit user inputPin and returns true if it matches the 5-digit encrypted pin */

int main() {
    const int MY_PIN[] = {2, 0, 9, 1, 0};
    const int MY_PIN_SIZE = 5;
    const int STD_SIZE = 10;

    int cipherCode[STD_SIZE];
    int encryptedPin[STD_SIZE];
    int inputPin;

    bool testSuccess;

    // Print to screen and generate cipher code
    initializeProgram(cipherCode, STD_SIZE);
    // Encrypt MY_PIN and save as encryptedPin
    pinEncrypt(MY_PIN, encryptedPin, cipherCode, MY_PIN_SIZE);
    // Get PIN from from user and save as integer "inputPin"
    getPin(inputPin);
    // Test to see if user input matches the encoded pin
    testSuccess = pinValidator(inputPin, encryptedPin);

    if (testSuccess)
        cout << "Your PIN is correct" << endl;
    else
        cout << "Your PIN is not correct" << endl;

    return 0;
}

void initializeProgram (int cipherCode[], int arrSize){
    // Print first line
    cout << "Please enter your PIN according to the following mapping:" << endl;

    // Print PIN line to screen
    cout << "PIN:\t";
    for (int i = 0; i < 10; i++){
        cout << i << " ";
    }
    cout << endl;

    // Print NUM line to screen
    cout << "NUM:\t";
    cipherGenerator(cipherCode, arrSize);
    for (int j = 0; j < arrSize;  j++)
        cout << cipherCode[j] << " ";
    cout << endl;
}

void cipherGenerator (int arr[], int arrSize){
    srand(time(0));
    for (int i = 0; i < arrSize; i++){
        arr[i] = rand() % 10;
    }
}

void pinEncrypt (const int inputPin[], int outputPin[], const int cipherCode[], const int arrSize){
    int encodeInt;

    for (int i = 0; i < arrSize; i++){
        encodeInt = inputPin[i];
        outputPin[i] = cipherCode[encodeInt];
    }
}

void getPin (int& input){
    using namespace std;
    const int ARRAY_SIZE = 6;
    char inputPin[ARRAY_SIZE];

    char nextDigit;
    cin.get(nextDigit);
    int index = 0;
    while (index < ARRAY_SIZE - 1) {
        if (isdigit(nextDigit)) {
            inputPin[index] = nextDigit;
            index++;
        }
        cin.get(nextDigit);
    }
    inputPin[index] = '\0';
    input = stoi(inputPin);
}

bool pinValidator(int inputPin, const int encryptedPin[]){
    const int ARRAY_SIZE = 5;
    int encryptedPinInt = 0;

    // First convert scrambledPin to int
    for (int i = 0, j = ARRAY_SIZE - 1; i < ARRAY_SIZE; i++, j--){
        encryptedPinInt += encryptedPin[i] * static_cast<int>(pow(10, j));
    }

    // Second, compare to inputPin
    if (encryptedPinInt == inputPin)
        return true;
    else
        return false;
}