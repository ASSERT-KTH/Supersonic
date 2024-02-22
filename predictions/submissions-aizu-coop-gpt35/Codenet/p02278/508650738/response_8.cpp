The code provided is a C++ program that calculates the minimum cost of merging an array of integers. The program uses the QuickFind data structure to group together elements that should be merged. The algorithm works as follows:

1. Read the number of elements `n` from the input.
2. Read the elements of the array `a` from the input.
3. Create a copy of array `a` and sort it to obtain array `b`.
4. Create two maps `p` and `q` to store the positions of each element in arrays `a` and `b`, respectively.
5. Initialize a QuickFind data structure with size `n`.
6. Iterate over each element in array `b` and merge the corresponding elements in array `a` using the QuickFind data structure.
7. Calculate the minimum cost of merging by considering all groups in the QuickFind data structure. The cost is calculated as the sum of the minimum element in the group multiplied by the size of the group minus 2, and the sum of all elements in the group plus the minimum element multiplied by the size of the group plus 1.
8. Print the minimum cost.
