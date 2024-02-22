Optimization Steps:

1. Remove unnecessary header files: The program includes several unnecessary header files such as `<bits/stdc++.h>`, `<cfloat>`, and `<cmath>`. We can remove these header files to improve compilation speed and reduce unnecessary dependencies.

2. Replace `typedef` with `using`: Instead of using `typedef` to define `ll` and `ull`, we can use the `using` keyword, which is recommended in modern C++. This will improve code readability.

3. Replace `strcpy` with `std::strcpy`: The program defines a custom `strcpy` function which is not necessary. We can use the standard `std::strcpy` function from the `<cstring>` header instead.

4. Use `std::string` instead of character arrays: Instead of using character arrays for `from`, `to`, and `message` fields in `struct Info` and `struct Data`, we can use `std::string` for better memory management and to avoid potential buffer overflows.

5. Use `std::vector` instead of fixed-size arrays: Instead of using fixed-size arrays for `Info OK[N]` and `Info NOT[N]`, we can use `std::vector` to dynamically manage the size of the arrays.

6. Use `std::unordered_set` instead of `std::set`: The program uses `std::set` to store unique values, but `std::unordered_set` provides faster insertion and lookup operations. We can replace `std::set` with `std::unordered_set` to improve performance.

7. Avoid unnecessary string comparisons: The program uses `strCmp` and `ambiguousCmp` functions to compare strings. However, we can use the `==` operator directly to compare `std::string` objects, which is more efficient.

8. Avoid unnecessary string length calculations: The `strCmp` function calculates the lengths of strings using loops, but we can use the `std::string` `size()` function to get the length of the strings instead.

9. Use range-based for loops: Instead of using traditional `for` loops with index variables, we can use range-based `for` loops to improve code readability and reduce the chance of off-by-one errors.

10. Avoid unnecessary `continue` statements: The program includes several `continue` statements in nested loops. We can remove these `continue` statements to simplify the code and improve performance.

11. Use `emplace` instead of `push`: When pushing elements into a `std::queue`, we can use `emplace` instead of `push` to construct the elements in-place, which can improve performance.

12. Use a more appropriate container for the data: Instead of using a `std::queue` to store the data, we can use a `std::vector` and sort it at the end. This can reduce memory usage and improve performance.
