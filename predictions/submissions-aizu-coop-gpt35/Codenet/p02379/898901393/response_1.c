The provided code calculates the distance between two points using the Euclidean distance formula. However, there are a few areas where the code can be optimized for better performance and memory usage.

1. Avoid using the `math.h` library: The `math.h` library is not necessary for calculating the square root of a number. Instead, we can use a more efficient approximation algorithm, such as the Newton-Raphson method or the Babylonian method, to calculate the square root.

2. Avoid unnecessary variable assignments: In the `distance()` function, the temporary variable `temp` is assigned the value of the square of the distance. However, this assignment is not necessary. We can directly return the square root of the distance without assigning it to a temporary variable.

3. Use pass-by-reference instead of pass-by-value: The `distance()` function currently takes two `point` structs as arguments, which are passed by value. This means that a copy of each struct is made when the function is called. However, since the `distance()` function only reads the values of the `point` structs, we can pass them by reference instead to avoid the overhead of making copies.

4. Avoid using the `scanf()` function for input: The `scanf()` function can be slow when reading input from the standard input stream. Instead of using `scanf()`, we can use the `fgets()` function to read a line of input and then parse the values from that line.

5. Use a more efficient output format: The `printf()` function currently uses the `%.5f` format specifier to print the distance with 5 decimal places. However, this format specifier can be slow and inefficient. We can use the `%g` format specifier instead, which automatically selects the appropriate precision and avoids unnecessary trailing zeros.
