#include <algorithm>
#include <stdio.h>
using namespace std;
#define MAX 1000001
int n, x, a[30];
bool dp[MAX], prime[MAX];

void sieve() {
  fill(begin(prime), end(prime), false);
  prime[2] = true;
  for (int i = 3; i * i <= MAX; i += 2) {
    if (prime[i])
      for (int j = i * i; j <= MAX; j += i)
        prime[j] = false;
  }
}

int main() {
  sieve();
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    fill(begin(dp), begin(dp) + x + 1, false);
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (dp[i - a[j]]) {
          dp[i] = true;
          break;
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