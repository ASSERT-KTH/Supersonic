The provided code calculates the win rates for two players playing a game. The code uses nested loops to iterate through all possible combinations of moves for the two players. For each combination, it calculates the total score for each player and updates the win rates accordingly.

However, the current implementation has several performance issues:

1. Redundant Memory Allocation: The code allocates memory for the `num` and `a` arrays in every iteration of the outermost loop. This is unnecessary as the size and contents of these arrays don't change throughout the iterations. Moving the array declarations outside the loop will eliminate this redundant memory allocation.

2. Inefficient Looping: The code uses nested loops with fixed sizes to iterate through all possible combinations of moves. This approach is not scalable and results in a high time complexity. A more efficient approach is needed to reduce the number of iterations.

3. Redundant Calculations: The code calculates the win rates using floating-point division and multiplication operations, which can be computationally expensive. These operations can be avoided or replaced with more efficient alternatives.

To optimize the code, we can follow the following steps:

Step 1: Move Array Declarations
- Move the declarations of the `num` and `a` arrays outside the outermost loop. This will avoid unnecessary memory allocation in every iteration.

Step 2: Use Permutation Algorithm
- Instead of using nested loops with fixed sizes to iterate through all possible combinations of moves, we can use a permutation algorithm to generate the permutations of moves. This will reduce the number of iterations and improve efficiency.

Step 3: Avoid Floating-Point Operations
- Instead of using floating-point division and multiplication operations to calculate the win rates, we can use integer arithmetic to perform the calculations. This will avoid the overhead of floating-point operations and improve efficiency.

Step 4: Update Output Format
- The current code rounds the win rates to 5 decimal places. To improve efficiency, we can update the output format to round the win rates to 2 decimal places.
