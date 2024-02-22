#include <cstdio>
#define MAX 999999

// We will use positive values to store prime number counts and negative values to mark non-prime numbers.
int num_prime[MAX + 1];

int main() {
  num_prime[2] = 1;
  for (int i = 2; i * i <= MAX; ++i) {
    if (num_prime[i] >= 0) {
      for (int j = i * i; j <= MAX; j += i) {
        num_prime[j] = -1;
      }
    }
    if (i < MAX) {
      num_prime[i + 1] = num_prime[i] + (num_prime[i + 1] >= 0 ? 1 : 0);
    }
  }
  int n;
  while (scanf("%d", &n) != EOF) {
    printf("%d\n", num_prime[n]);
  }
  return 0;
}