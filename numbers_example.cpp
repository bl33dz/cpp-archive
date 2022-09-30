#include <iostream>
#include "numbers.h"

using namespace std;

int main() {
    Numbers nums;
    int number;

    inputNumber(&nums);

    cout << endl;
    cout << "Bubble sort: ";
    Numbers res = bubbleSort(nums);
    printNumber(res);

    cout << "Selection sort: ";
    Numbers res2 = selectionSort(nums);
    printNumber(res2);

    cout << "Insertion sort: ";
    Numbers res3 = insertionSort(nums);
    printNumber(res3);

    cout << endl;
    cout << "Number to find: ";
    cin >> number;
    cout << endl;

    int search = binarySearch(nums, number);
    if(search == -1)
        cout << "Number not found in vector";
    else
        cout << "Number " << number << " found at index " << search;
    cout << endl;

    int search2 = sequentialSearch(nums, number);
    if(search == -1)
        cout << "Number not found in vector";
    else
        cout << "Number " << number << " found at index " << search;
    cout << endl;

    return 0;
}
