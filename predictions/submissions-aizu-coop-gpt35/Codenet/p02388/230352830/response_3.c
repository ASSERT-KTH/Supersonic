#include <stdio.h>

#pragma GCC optimize ("O3")

int main(void) {
  long long x;
  scanf("%lld", &x);
  printf("%lld\n", x * x * x);
  return 0;
}