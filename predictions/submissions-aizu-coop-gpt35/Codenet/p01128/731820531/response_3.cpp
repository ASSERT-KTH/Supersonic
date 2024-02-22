Code Analysis:
1. The code includes a large number of unnecessary header files, such as `<algorithm>`, `<bitset>`, `<cassert>`, etc. These should be removed to reduce compilation time and unnecessary memory usage.
2. The code includes a large number of unnecessary function templates and overloaded operators. These should be removed to simplify the code and improve readability.
3. The code includes a large number of unnecessary utility functions, such as `uniq`, `to_s`, `to_T`, etc. These functions are not used in the main program and can be removed.
4. The code includes unnecessary macros, such as `rep`, `foreach`, `rforeach`, etc. These macros can be replaced with regular for loops and iterators to improve code clarity.
5. The code includes unnecessary typedefs, such as `typedef long long ll`, `typedef pair<int, int> pint`, etc. These typedefs can be replaced with the actual types to improve code clarity.
6. The code includes unnecessary geometric algorithms and data structures, such as `Line`, `Seg`, `Circle`, etc. These are not used in the main program and can be removed.
7. The code includes unnecessary input/output functions, such as `fix_pre`, `fast_io`, etc. These functions are not used in the main program and can be removed.
8. The code includes unnecessary constants and variables, such as `dx`, `dy`, `PI`, etc. These can be removed as they are not used in the main program.

Optimization Strategy:
1. Remove unnecessary header files to reduce compilation time and unnecessary memory usage.
2. Remove unnecessary function templates and overloaded operators to simplify the code and improve readability.
3. Remove unnecessary utility functions to reduce code complexity and improve performance.
4. Replace macros with regular for loops and iterators to improve code clarity.
5. Remove unnecessary typedefs to improve code clarity.
6. Remove unnecessary geometric algorithms and data structures to reduce code complexity and improve performance.
7. Remove unnecessary input/output functions to reduce code complexity and improve performance.
8. Remove unnecessary constants and variables to reduce code complexity and improve performance.

Step-by-Step Explanation:
1. Remove unnecessary header files:
   - Remove the following unnecessary header files: `<algorithm>`, `<bitset>`, `<cassert>`, `<cfloat>`, `<climits>`, `<cmath>`, `<complex>`, `<cstdio>`, `<cstdlib>`, `<cstring>`, `<ctime>`, `<fstream>`, `<functional>`, `<iomanip>`, `<iostream>`, `<list>`, `<map>`, `<memory>`, `<numeric>`, `<queue>`, `<set>`, `<sstream>`, `<stack>`, `<string>`, `<utility>`, `<vector>`.
2. Remove unnecessary function templates and overloaded operators: