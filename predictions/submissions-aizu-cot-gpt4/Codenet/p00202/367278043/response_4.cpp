#include <algorithm>
#include <stdio.h>
using namespace std;
int n, x, a[30];
bool dp[1000001], prime[1000001];

void generatePrimes() {
  prime[0] = prime[2] = true;
  for (int i = 3; i <= 1000000; i += 2)
    prime[i] = true;
  for (int i = 3; i <= 1000; i++) {
    if (!prime[i])
      continue;
    for (int j = i; i * j <= 1000000; j += 2)
      prime[i * j] = false;
  }
}

int main() {
  generatePrimes();
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      if(dp[i]) continue;
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
  return 0;
}