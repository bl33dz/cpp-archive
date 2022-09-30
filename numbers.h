#ifndef NUMBERS_H
#define NUMBERS_H

struct Numbers {
    int *numbers;
    int size;
};

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printNumber(Numbers nums) {
    for(int i = 0; i < nums.size; i++)
        std::cout << nums.numbers[i] << " ";
    std::cout << std::endl;
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

int sequentialSearch(Numbers nums, int number) {
    for(int i = 0; i < nums.size; i++)
        if(nums.numbers[i] == number)
            return i;
    return -1;
}

#endif
