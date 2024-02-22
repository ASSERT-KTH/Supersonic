#include <cstdio>
#include <cstdint>
int main() {
    int64_t a = 1;
    int i, n;
    scanf("%d", &n);
    if(n > 1) {
        for (i = 2; i <= n; i++) {
            a = a * i;
        }
    }
    printf("%lld\n", a);
    return 0;
}