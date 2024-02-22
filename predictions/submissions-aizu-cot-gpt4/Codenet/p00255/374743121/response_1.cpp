#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
    while(true) {
        long long n;
        scanf("%lld", &n);
        if (!n)
            break;
        long long a = 0, s = 0;
        for (long long i = 0; i < n; ++i) {
            scanf("%lld", &a);
            s += a;
        }
        for (long long i = 1; i <= n; ++i)
            a = max(i * s, a);
        printf("%lld\n", a);
    }
    return 0;
}