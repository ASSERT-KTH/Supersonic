#include <cstdio>

int main() {
  unsigned long long a = 1;
  unsigned int n;
  scanf("%u", &n);
  
  for (unsigned int i = 1; i <= n; ++i) {
    a <<= i;
  }
  
  printf("%llu\n", a);
  return 0;
}