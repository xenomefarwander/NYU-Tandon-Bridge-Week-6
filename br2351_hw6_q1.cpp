/* Question 1
 * 1. Implement the function: int minInArray(int arr[], int arrSize)
 * This function is given arr, an array of integers, and its logical size, arrSize. When called,
 * it returns the minimum value in arr.
 * 2. Write a program that reads from the user a sequence of 20 integers (unnecessarily different
 * from one another) into an array, and outputs the minimum value, and all the indices it
 * appears in the array.
 * Your program should interact with the user exactly as it shows in the following example:
 * Please enter 20 integers separated by a space:
 * 14 5 12 5 6 14 5 12 14 12 14 6 8 7 5 136 9 2189 10 6
 * The minimum value is 5, and it is located in the following indices: 1 3 6 14
 * Note: You may want to define additional functions for your program to use.*/

#include <iostream>
using namespace std;

const int ARRAY_SIZE = 20;

int minInArray(const int arr[], int arrSize);

void getArray(int arr[], int arrSize);

int main() {

    int inputList[20];
    int minVal;

    cout << "Please enter 20 integers separated by a space:" << endl;
    getArray(inputList, ARRAY_SIZE);
    minVal = minInArray(inputList, ARRAY_SIZE);

    cout << "The minimum value is " << minVal << ", and it is located in the following indices: ";

    // Prints indices where minVal is found in array
    for (int i = 0; i < ARRAY_SIZE; i++){
        if (inputList[i] == minVal)
            cout << i << " ";
    }

    return 0;
}

int minInArray(const int arr[], int arrSize){
    int minValue;
    int i;

    minValue = arr[0];
    for (i = 1; i < arrSize; i += 1){
        if (arr[i] < minValue)
            minValue = arr[i];
    }
    return minValue;
}

void getArray(int arr[], int arrSize){

    int inputInt;
    int index;

    // Reads in value from cin until all array indices are assigned
    for (index = 0; index < arrSize; index +=1) {
        cin >> inputInt;
        arr[index] = inputInt;
    }

    return;
}
