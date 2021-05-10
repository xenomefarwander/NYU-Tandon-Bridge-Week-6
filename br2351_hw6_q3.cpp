/*Question 3:
 * Implement following functions:
 * a. void reverseArray(int arr[], int arrSize)
 * That takes arr, an array of integers, and its size, arrSize. When called, it reorders the
 * elements of the array to appear in a reverse order.
 * For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray, arr
 * will look like: [4, 3, 2, 1].
 * b. void removeOdd(int arr[], int& arrSize)
 * That takes arr, an array of integers, and its size, arrSize. When called, the function
 * alters arr so that the only numbers in it at the end are the even ones, which should remain
 * in their original relative order.
 * Additionally, the function updates arrSize so it contains the new logical size of the array
 * after removing the odd numbers (note that arrSize is a parameter used both for input
 * and output).
 * For example, if arr is an array containing [1, 2, 3, 4], after calling removeOdd, arr will
 * look like: [2, 4], and the parameter arrSize will update to 2. Notice the values in arr[2]
 * and arr[3] are discarded.
 * c. void splitParity(int arr[], int arrSize)
 * That takes arr, an array of integers, and its size, arrSize. When called, the function
 * changes the order of numbers in arr so that all the odd numbers will appear first, and all
 * the even numbers will appear last. Note that the inner order of the odd numbers and the
 * inner order of the even numbers don’t matter.
 * For example, if arr is an array containing [1, 2, 3, 4], after calling splitParity, arr
 * could look like: [3, 1, 2, 4].*/

#include <iostream>
using namespace std;

void reverseArray(int arr[], int arrSize);
/* Takes arr, an array of integers, and its size, arrSize. When called, it reorders the
 * elements of the array to appear in a reverse order.
 * For example, if arr is an array containing [1, 2, 3, 4], after calling reverseArray, arr
 * will look like: [4, 3, 2, 1].*/

void removeOdd(int arr[], int& arrSize);
/* Function takes an array and its length, outputs an array with no odd numbers and
 * updates arrSize accordingly */

void splitParity(int arr[], int arrSize);
/* When called, the function changes the order of numbers in arr so that all the odd numbers
 * will appear first, and all the even numbers will appear last. Note that the inner order
 * of the odd numbers and the inner order of the even numbers don’t matter.
 * For example, if arr is an array containing [1, 2, 3, 4], after calling splitParity, arr
 * could look like: [3, 1, 2, 4]. */

void printArray(int arr[], int arrSize);

int main() {
    int arr1[10] = {9, 2, 14, 12, -3};
    int arr1Size = 5;
    int arr2[10] = {21, 12, 6, 7, 14};
    int arr2Size = 5;
    int arr3[10] = {3, 6, 4, 1, 12};
    int arr3Size = 5;
    reverseArray(arr1, arr1Size);
    printArray(arr1, arr1Size);
    removeOdd(arr2, arr2Size);
    printArray(arr2, arr2Size);
    splitParity(arr3, arr3Size);
    printArray(arr3, arr3Size);
    return 0;
}

void printArray(int arr[], int arrSize){
    int i;
    for (i = 0; i < arrSize; i++) {
        cout<<arr[i]<<' ';
    }
    cout<<endl;
}

void reverseArray(int arr[], int arrSize){

    int start = 0;
    int end = arrSize;
    int temp;

    while (start < end){
        end -= 1;
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start += 1;
    }
}

void removeOdd(int arr[], int& arrSize){

    int i, j;

    // Finds even values in arr[] and puts them at front of array
    j = 0;
    for (i = 0; i < arrSize; i += 1) {
        if (arr[i] % 2 == 0){
            arr[j] = arr[i];
            j++;
        }
    }
    // Update array size to reflect only evens pushed to left of array.
    arrSize = j;
}

void splitParity(int arr[], int arrSize){

    int i = 0;
    int j = arrSize - 1;
    int temp;

    while (i < j){
        if (arr[i] % 2 == 1) { // Case where i is odd
            i++;
            continue;
        } else if (arr[j] % 2 == 1){ // Case where i is even, check j if odd
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        } else { // case where i is even, j is even
            j--;
        }
    }
}