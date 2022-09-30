#include<iostream>

using namespace std;

struct Numbers {
    int *numbers;
    int size;
};

int binarySearch(Numbers nums, int number) {
    int min = 0, max = nums.size - 1;
    int median;

    while(min <= max) {
        median = (min + max) / 2;

        if (nums.numbers[median] == number)
            return median;
        else if(nums.numbers[median] < number)
            min = median + 1;
        else
            max = median - 1;
    }
    return -1;
}

int main() {
    Numbers nums;
    int number;

    cout << "Size: ";
    cin >> nums.size;

    nums.numbers = (int*)malloc(sizeof(int) * nums.size);

    cout << "Numbers: ";
    for(int i = 0; i < nums.size; i++) {
        cin >> nums.numbers[i];
    }

    cout << "Number to find: ";
    cin >> number;
    cout << endl;

    int search = binarySearch(nums, number);
    if(search == -1) {
        cout << "Number not found in array";
    } else {
        cout << "Number " << number << " found at index " << search;
    }
    cout << endl;

    return 0;
}
