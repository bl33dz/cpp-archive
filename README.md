# cpp-archive

<p align="center">
    <img src=https://anime-girls-holding-programming-books.netlify.app/static/4a00ee5a5a9ac67a26fc0d3e44123dab/5890a/Sakura_Nene_CPP_Covered.jpg>
</p>

Some C++ functions commonly used in informatics laboratory practicum.

### numbers.h
Struct:
```c++
struct Numbers {
    int *numbers;
    int size;
}
```

Functions:
- bubbleSort
- selectionSort
- insertionSort
- binarySearch
- sequentialSearch
- printNumber
- inputNumber

Example:

![test](https://s5.gifyu.com/images/teste2d6972a43c1cc55.gif)

### vector.cpp
 Vectors are sequence containers representing arrays that can change in size.\
 Full Documentation: https://cplusplus.com/reference/vector/vector/.

Functions:
- inputVector
- printVector
- bubbleSort (same with `numbers.h` but using vector)
- binarySearch (same with `numbers.h` but using vector)

Notes:
- Add element at the end: `vector.push_back(value)`
- Delete last element: `vector.pop_back()`
- Insert elements: `vector.insert(vector.begin()+n)` (Using iterator)
- Erase elements: `vector.erase(vector.begin()+n, value)` (Using iterator)
- Swap content: `vector.swap(another_vector)`
- Clear content: `vector.clear()`
- Iterators: `vector.begin()`, `vector.end()`, etc.

Example:

![example](https://s4.gifyu.com/images/example61af3c825d4f08f9.gif)
