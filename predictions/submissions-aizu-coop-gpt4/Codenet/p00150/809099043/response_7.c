#include <stdio.h>
#include <math.h>

int isprime1(int n) {
  if (n <= 1) return 0;
  if (n == 2) return 1;
  if (n % 2 == 0) return 0;
  int m = sqrt(n);
  for (int i = 3; i <= m; i += 2) {
    if (n % i == 0)
      return 0;
  }
  return 1;
}

int main() {
  int n, p, q;
  scanf("%d", &n);
  int previous_prime = isprime1(n);
  while (n > 0) {
    for (int i = n; i >= 5; --i) {
      int current_prime = isprime1(i - 2);
      if (previous_prime && current_prime) {
        p = i - 2;
        q = i;
        break;
      }
      previous_prime = current_prime;
    }
    printf("%d %d\n", p, q);
    scanf("%d", &n);
    previous_prime = isprime1(n);
  }
  return 0;
}