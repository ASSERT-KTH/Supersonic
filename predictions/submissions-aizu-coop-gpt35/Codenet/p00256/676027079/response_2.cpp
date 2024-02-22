The given code converts dates between two different representations: the standard Gregorian calendar and a custom calendar system. The code reads input from the user, converts the date based on the input format, and prints the converted date.

Upon analysis, the following potential performance bottlenecks and areas for optimization can be identified:

1. The `check` function is called multiple times to determine if a year is a leap year. The result of this function can be precomputed and stored in an array to avoid repeated calculations.

2. In the `M2S` function, there are multiple divisions and modulo operations performed to calculate the year, month, and day components of the date. These operations can be minimized by using a more efficient algorithm.

3. In the `S2M` function, there is a loop that calculates the number of days from the custom calendar's start date to the input date. This loop can be replaced with direct calculations using the formula for the custom calendar.

4. The `vector<int> a` is used to store the input values for date conversion. However, the use of a vector is unnecessary since the input size is fixed. Using a fixed-size array to store the input values will be more efficient.

Based on these observations, the following optimization strategy can be formulated:

1. Precompute leap year information and store it in an array.
2. Optimize the calculations in the `M2S` function to reduce divisions and modulo operations.
3. Replace the loop in the `S2M` function with direct calculations using the custom calendar formula.
4. Replace the vector with a fixed-size array for storing input values.
