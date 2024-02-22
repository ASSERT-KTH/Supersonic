#include <bitset>
#include <stdio.h>
using namespace std;

const int MAX_N = 30;
const int MAX_X = 1000001;

int n, x, a[MAX_N];
bitset<MAX_X> dp, prime;

int main() {
  prime.set(0);
  prime.set(2);
  for (int i = 3; i * i < MAX_X; i += 2) {
    if (prime[i]) {
      for (int j = i * i; j < MAX_X; j += 2 * i)
        prime.reset(j);
    }
  }

  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);

    sort(a, a + n);

    dp.reset();
    dp.set(0);

    for (int i = 0; i < n; i++) {
      for (int j = x; j >= a[i]; j--) {
        if (dp[j - a[i]]) {
          dp.set(j);
          break;
        }
      }
    }

    for (int i = x; i >= 0; i--) {
      if (i == 0 || (dp[i] && prime[i])) {
        printf(i ? "%d\n" : "NA\n", i);
        break;
      }
    }
  }
}