#include <stdio.h>
#include <stdbool.h>

#define MAX_N 30
#define MAX_X 1000000

bool prime[MAX_X + 1];

int main() {
  prime[0] = false;
  prime[1] = false;
  for (int i = 2; i <= MAX_X; i++)
    prime[i] = true;

  for (int i = 2; i * i <= MAX_X; i++) {
    if (prime[i]) {
      for (int j = i * i; j <= MAX_X; j += i)
        prime[j] = false;
    }
  }

  int n, x, a[MAX_N];
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    int sum = 0;
    for (int i = 0; i < n; i++)
      sum += a[i];

    bool isPrime = prime[sum];
    if (isPrime)
      printf("%d\n", sum);
    else
      printf("NA\n");
  }
}