#include <algorithm>
#include <stdio.h>
using namespace std;
int n, x, a[30];
bool dp[1000001], prime[1000001];
void sieveOfEratosthenes() {
    fill(prime, prime + 1000001, true);
    prime[0] = prime[1] = false;
    for (int p = 2; p * p <= 1000000; p++) {
        if (prime[p]) {
            for (int i = p * p; i <= 1000000; i += p)
                prime[i] = false;
        }
    }
}
int main() {
  sieveOfEratosthenes();
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    fill(dp, dp + x + 1, false);
    dp[0] = true;
    for (int i = 0; i < n; i++)
      for(int j = x; j >= a[i]; j--)
        if(dp[j - a[i]])
          dp[j] = true;
    for (int i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
  return 0;
}