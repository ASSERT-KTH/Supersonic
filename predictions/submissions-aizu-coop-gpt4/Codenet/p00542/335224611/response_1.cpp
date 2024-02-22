#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);

    // find the minimum of first 4 numbers
    int min_val = min(min(a, b), min(c, d));

    // find the maximum of last 2 numbers
    int max_val = max(e, f);

    int ans = a + b + c + d - min_val + max_val;
    printf("%d\n", ans);
  
    return 0;
}