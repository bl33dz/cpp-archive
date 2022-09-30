#include<iostream>
#include<vector>

using namespace std;

int binarySearch(vector<int> nums, int number) {
    int min = 0, max = nums.size() - 1;
    int median;

    while(min <= max) {
        median = (min + max) / 2;

        if (nums[median] == number)
            return median;
        else if(nums[median] < number)
            min = median + 1;
        else
            max = median - 1;
    }
    return -1;
}

int main() {
    vector<int> numbers;
    int number, n;

    cout << "Size: ";
    cin >> n;

    cout << "Numbers: ";
    for(int i = 0; i < n; i++) {
        int input;
        cin >> input;
        numbers.push_back(input);
    }

    cout << "Number to find: ";
    cin >> number;
    cout << endl;

    int search = binarySearch(numbers, number);
    if(search == -1)
        cout << "Number not found in vector";
    else
        cout << "Number " << number << " found at index " << search;
    cout << endl;

    return 0;
}
