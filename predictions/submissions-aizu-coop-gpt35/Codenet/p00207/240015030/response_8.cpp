Upon analyzing the given code, I have identified several areas that can be optimized for better performance and memory usage:

1. Redundant Memory Allocation:
   - The `Board` array is allocated with a size of 102x102, but the actual board size is determined by the input values of `w` and `h`. This leads to unnecessary memory allocation and can be optimized to allocate memory based on the actual board size.

2. Unnecessary Board Initialization:
   - The `Board` array is initialized with -1 for each cell before reading the input values. However, this initialization is unnecessary because all cells will be overwritten with valid values from the input. Removing this initialization step will improve performance.

3. Recursive DFS:
   - The Depth-First Search (DFS) algorithm is implemented using recursive function calls. While this approach is simple, it can lead to stack overflow errors for large input sizes. Optimizing the DFS algorithm to use an iterative approach will improve performance and avoid potential stack overflow errors.

4. Inefficient Board Representation:
   - The `Board` array is represented as a 2D array of integers. However, the problem statement only requires checking if two cells have the same color or not. Storing the board as a 2D array of booleans instead of integers will significantly reduce memory usage.

5. Compiler Optimization:
   - Enabling compiler optimizations can further improve the performance of the code. Using appropriate compiler flags or pragma directives, such as loop unrolling or vectorization, can help the compiler generate more optimized machine code.
