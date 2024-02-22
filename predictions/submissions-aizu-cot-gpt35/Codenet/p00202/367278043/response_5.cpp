#include <stdio.h>
using namespace std;

const int MAX_N = 30;
const int MAX_X = 1000000;

int n, x, a[MAX_N];
bool dp[MAX_X], prime[MAX_X];

int main() {
  prime[0] = true, prime[2] = true;
  for (int i = 3; i * i <= MAX_X; i += 2)
    prime[i] = true;

  for (int i = 3; i * i <= MAX_X; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= MAX_X; j += 2)
      prime[i * j] = false;
  }

  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a, a + n);

    for (int i = 0; i < x; i++)
      dp[i] = false;

    dp[0] = true;

    for (int i = 1; i < x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (dp[i - a[j]]) {
          dp[i] = true;
          break;
        }
      }
    }

    for (int i = x - 1; i >= 1; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}