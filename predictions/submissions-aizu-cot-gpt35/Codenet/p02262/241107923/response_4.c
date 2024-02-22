Step 1: Remove unnecessary global variables
- The variables `count`, `temp`, and `temp_temp` are not used outside of the `ShellSort` function. Therefore, they can be declared as local variables within the function.

Step 2: Optimize ShellSort loop
- The loop in the `ShellSort` function that calculates the values of the `h` array can be optimized. The current implementation uses a fixed size of 20 for the `h` array. However, the actual size needed is determined by the input value `num`. We can calculate the maximum required size of the `h` array based on `num` and use a dynamically allocated array instead of a fixed-size array.

Step 3: Avoid unnecessary `temp_temp` variable
- The `temp_temp` variable is used only to store the value of `temp` when `i` is equal to `temp`. We can eliminate the need for this variable by using `temp` directly in the `insertionSort` function.
