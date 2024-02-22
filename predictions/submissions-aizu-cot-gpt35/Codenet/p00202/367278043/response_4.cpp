#include <stdio.h>

bool prime[1000001];

int main() {
  prime[0] = true, prime[2] = true;
  for (int i = 3; i * i <= 1000000; i += 2) {
    if (!prime[i]) {
      for (int j = i * i; j <= 1000000; j += i)
        prime[j] = true;
    }
  }

  int n, x, a[30];
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    bool dp[1000001] = {false};
    dp[0] = true;

    for (int i = 0; i < n; i++) {
      if (a[i] <= x && prime[a[i]]) {
        dp[a[i]] = true;
        for (int j = a[i]; j <= x; j++) {
          if (dp[j - a[i]])
            dp[j] = true;
        }
      }
    }

    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}