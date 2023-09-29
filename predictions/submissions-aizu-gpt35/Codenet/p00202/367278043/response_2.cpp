#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAXN = 30;
const int MAXX = 1000000;
int n, x, a[MAXN];
bool dp[MAXX + 1], prime[MAXX + 1];
int main() {
  memset(prime, true, sizeof(prime));
  prime[0] = false, prime[1] = false;
  for (int i = 2; i * i <= MAXX; ++i) {
    if (prime[i]) {
      for (int j = i * i; j <= MAXX; j += i)
        prime[j] = false;
    }
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    sort(a, a + n);
    memset(dp, false, sizeof(dp));
    dp[0] = true;
    for (int i = 0; i < n; ++i) {
      for (int j = a[i]; j <= x; ++j) {
        dp[j] |= dp[j - a[i]];
      }
    }
    for (int i = x; i >= 0; --i) {
      if (dp[i] && prime[i]) {
        printf("%d\n", i);
        goto end;
      }
    }
    puts("NA");
    end:;
  }
  return 0;
}