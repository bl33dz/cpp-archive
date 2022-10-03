/* Vectors in C++ are the dynamic arrays that are used to store data. */

#include <iostream>
#include <vector>

using namespace std;

void swap(int *a, int *b) { // function to swap variable
    int temp = *a;
    *a = *b;
    *b = temp;
}

void inputVector(vector<int> &vec) {
    int num = 0;
    while(cin) {
        if(cin >> num)
            vec.push_back(num);
    }
}

void printVector(vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
}

// Convert bubbleSort in numbers.h to vector bubbleSort
vector<int> bubbleSort(vector<int> vec) {
    int i, j;
    for(i = 0; i < vec.size(); i++)
        for(j = 0; j < vec.size(); j++)
            if(vec[j] > vec[i])
                swap(&vec[i], &vec[j]);
    return vec;
}

// Convert binarySearch in numbers.h to vector binarySearch
int binarySearch(vector<int> vec, int number) {
    int min = 0, max = vec.size() - 1;
    int median;

    while(min <= max) {
        median = (min + max) / 2;

        if (vec[median] == number)
            return median;
        else if(vec[median] < number)
            min = median + 1;
        else
            max = median - 1;
    }
    return -1;
}

int main() {
    vector<int> nums;

    cout << "Input non-integer value to stop." << endl << endl;

    cout << "Input: ";
    inputVector(nums);
    cin.clear(); // clear cin
    cout << "Vector: ";
    printVector(nums);

    vector<int> sorted;
    sorted = bubbleSort(nums);
    cout << "Vector(sorted): ";
    printVector(sorted);

    int number, result;
    cout << "Number to find: ";
    cin >> number;
    result = binarySearch(sorted, number);
    if(result != -1)
        cout << "Number " << number << " found at index " << result;
    else
        cout << "Number not found in vector";
    cout << endl;

    return 0;
}
