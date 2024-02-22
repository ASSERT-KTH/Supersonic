#include <cstdio>

int main() {
  long long a = 1;
  int n;
  scanf("%d", &n);
  for (int i = 2; i <= n; i++) {
    a = a * i;
  }
  printf("%lld\n", a);
  return 0;
}