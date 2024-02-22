#include <cstdio>

int main() {
  int n;
  long long min, max, sum;
  scanf("%d", &n);
  scanf("%lld", &min);
  max = min;
  sum = min;
  for (int i = 1; i < n; i++) {
    long long ii;
    scanf("%lld", &ii);
    if (ii < min) min = ii;
    if (ii > max) max = ii;
    sum += ii;
  }
  printf("%lld %lld %lld\n", min, max, sum);
}