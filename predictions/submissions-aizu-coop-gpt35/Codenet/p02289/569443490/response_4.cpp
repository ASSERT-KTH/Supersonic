Upon analyzing the provided code, I have identified several areas for optimization:

1. Inefficient memory allocation: The `Heap` class allocates memory for the `array` member in the constructor with a fixed size of 2,000,000. This results in unnecessary memory allocation and can be improved.

2. Inefficient max_heapify function: The `max_heapify` function is implemented as a member function of the `Heap` class, but it operates on a separate array passed as an argument. This function can be moved outside the class and optimized to operate directly on the `array` member.

3. Unnecessary swapping in heap_sort: The `heap_sort` function swaps the first and last elements of the array before calling `max_heapify`. However, this swapping is not necessary for the algorithm to work correctly. Removing this swapping step can improve performance.

4. Inefficient input parsing: The current implementation of parsing the input string in the `main` function is not optimal. It iterates over the string character by character, checking if each character is a digit. This can be improved using a more efficient parsing technique.
