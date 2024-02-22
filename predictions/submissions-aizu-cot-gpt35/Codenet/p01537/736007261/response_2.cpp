Step 1: Remove unnecessary headers and definitions
- The program includes several unnecessary headers such as `<algorithm>`, `<cmath>`, `<cstdio>`, `<cstring>`, `<ctime>`, `<iostream>`, `<sstream>`, `<string>`, and `<utility>`.
- The program defines several unnecessary macros such as `all`, `loop`, `rep`, `each`, `pb`, `eb`, `mp`, `mt`, `lb`, `ub`, `dump`, and `curr`.

Step 2: Remove unnecessary using statements
- The program uses the `using namespace std;` statement, which is generally considered bad practice. Instead, we should use the `std::` prefix to specify the standard library components.

Step 3: Optimize the `dist` function