#include <algorithm>
#include <stdio.h>
#include <bitset>
using namespace std;
const int MAXN = 30;
const int MAXX = 1e6 + 1;
int n, x, a[MAXN];
bitset<MAXX> dp, prime;
int main() {
  prime.set();
  prime[0] = prime[1] = false;
  for (int i = 2; i <= 1000; i += 1)
    if (prime[i])
      for (int j = i * i; j <= 1000000; j += i)
        prime[j] = false;
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    dp.reset();
    dp[0] = true;
    for (int i = 0, j; i < n; i++)
      for (j = a[i]; j <= x; j++)
        dp[j] |= dp[j - a[i]];
    for (int i = x; i >= 0; i--)
      if (dp[i] && prime[i]) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
  }
}