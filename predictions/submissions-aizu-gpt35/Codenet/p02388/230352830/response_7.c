#include <stdio.h>
int main(void) {
    long long int x; // use long long int to avoid integer overflow
    scanf("%lld", &x); // use %lld to match the long long int type
    printf("%lld\n", x * x * x);
    return 0;
}