The given program is already optimized in terms of running time and memory usage. However, there are some improvements we can make to the code to make it more readable and maintainable. Here are the steps for optimizing the program:

1. Remove unnecessary include statements: The program includes several unnecessary header files. We can remove the following include statements:
   - <cassert>: It is not used in the code.
   - <cstdlib>: It is not used in the code.
   - <deque>: It is not used in the code.
   - <iomanip>: It is not used in the code.
   - <iterator>: It is not used in the code.
   - <list>: It is not used in the code.
   - <map>: It is not used in the code.
   - <queue>: It is not used in the code.
   - <set>: It is not used in the code.
   - <sstream>: It is not used in the code.
   - <stack>: It is not used in the code.
   - <unordered_map>: It is not used in the code.
   - <valarray>: It is not used in the code.

2. Remove unnecessary typedefs: The program defines several typedefs that are not used in the code. We can remove the following typedef statements:
   - typedef unsigned int uint;
   - typedef unsigned char uchar;
   - typedef unsigned long long ull;
   - typedef pair<int, int> pii;
   - typedef pair<ll, ll> pll;
   - typedef vector<int> vi;

3. Remove unnecessary macros: The program defines several macros that are not used in the code. We can remove the following macro definitions:
   - #define REP(i, x) for (int i = 0; i < (int)(x); i++)
   - #define REPS(i, x) for (int i = 1; i <= (int)(x); i++)