After analyzing the given code, I have identified several areas for optimization:

1. Unnecessary includes: The code includes the entire `bits/stdc++.h` library, which is not recommended as it includes a large number of header files. We should only include the necessary headers for our program.

2. Redundant data: The `sum` array is unnecessary and can be eliminated. We can calculate the partial sums on the fly instead of storing them in an array.

3. Inefficient search: The `Find` function uses the `lower_bound` function multiple times, which performs a binary search each time. We can optimize this by performing a single binary search using the `upper_bound` function.

4. Redundant calculations: The `calc` function performs the `Find` function for each position. However, since the `calc` function is called in a loop, we can reuse the previous result to avoid redundant calculations.

5. Magic numbers: The value `INF` is defined as `1LL << 58`, which is not intuitive. We can replace it with a more meaningful value.

Based on these observations, here is the step-by-step optimization strategy:

1. Remove unnecessary includes: Replace `#include <bits/stdc++.h>` with the necessary headers, such as `<cstdio>` and `<algorithm>`.

2. Eliminate the `sum` array: Remove the `sum` array and calculate the partial sums on the fly in the `Find` function.

3. Optimize the `Find` function: Replace the multiple calls to `lower_bound` with a single call to `upper_bound`. Update the return condition accordingly.

4. Optimize the `calc` function: Remove the `Find` function and use the result from the previous iteration to avoid redundant calculations.

5. Replace magic number: Replace `INF` with a more meaningful value, such as `LLONG_MAX`.
