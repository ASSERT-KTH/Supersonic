#include <iostream>
using namespace std;

int main() {
    int a, b, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &a, &b, &e, &f);

    int min_val = min(a, b);
    int max_val = max(e, f);

    int ans = a + b + a + b - min_val + max_val;
    printf("%d\n", ans);

    return 0;
}