#include <algorithm>
#include <stdio.h>
using namespace std;

const int MAX_N = 30;
const int MAX_X = 1000000;

bool prime[MAX_X + 1];

int main() {
  // Sieve of Eratosthenes Initialization
  prime[0] = true;
  prime[2] = true;
  for (int i = 3; i <= MAX_X; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= MAX_X; j += 2)
      prime[i * j] = false;
  }

  int n, x, a[MAX_N];
  while (scanf("%d%d", &n, &x), n) {
    // Read input
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    // Dynamic Programming
    bool dp[MAX_X + 1] = { false };
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (dp[i - a[j]]) {
          dp[i] = true;
          break;
        }
      }
    }

    // Find largest prime
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
  return 0;
}