#include<iostream>

using namespace std;

struct Numbers {
    int *numbers;
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

Numbers bubbleSort(Numbers nums) {
    int i, j;
    for(i = 0; i < nums.size; i++)
        for(j = 0; j < nums.size; j++)
            if(nums.numbers[j] > nums.numbers[i])
                swap(&nums.numbers[i], &nums.numbers[j]);
    return nums;
}

Numbers selectionSort(Numbers nums) {
    int i, j, min;

    for(i = 0; i < nums.size - 1; i++) {
        min = i;
        for(j = i+1; j < nums.size; j++)
            if(nums.numbers[j] < nums.numbers[min])
                min = j;
        if(min != i)
            swap(&nums.numbers[min], &nums.numbers[i]);
    }

    return nums;
}

Numbers insertionSort(Numbers nums) {
    int i, j, k;

    for(i = 1; i < nums.size; i++) {
        k = nums.numbers[i];
        j = i - 1;
        while(j >= 0 && nums.numbers[j] > k) {
            nums.numbers[j + 1] = nums.numbers[j];
            j = j - 1;
        }
        nums.numbers[j + 1] = k;
    }

    return nums;
}

int main() {
    Numbers nums;

    cout << "Size: ";
    cin >> nums.size;

    nums.numbers = (int*)malloc(sizeof(int) * nums.size);

    cout << "Numbers: ";
    for(int i = 0; i < nums.size; i++) {
        cin >> nums.numbers[i];
    }

    cout << endl;
    cout << "Bubble sort: ";
    Numbers res = bubbleSort(nums);
    for(int i = 0; i < res.size; i++)
        cout << res.numbers[i] << " ";

    cout << endl;
    cout << "Selection sort: ";
    Numbers res2 = selectionSort(nums);
    for(int i = 0; i < res2.size; i++)
        cout << res2.numbers[i] << " ";

    cout << endl;
    cout << "Insertion sort: ";
    Numbers res3 = insertionSort(nums);
    for(int i = 0; i < res3.size; i++)
        cout << res3.numbers[i] << " ";

    cout << endl;
}
