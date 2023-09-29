#include <algorithm>
#include <stdio.h>
#define MAX_NUM 1000001
using namespace std;
int n, x, a[30];
bool dp[MAX_NUM], prime[MAX_NUM];
int main() {
  fill_n(prime, MAX_NUM, true);
  prime[0] = prime[1] = false;
  for (int i = 2; i * i <= MAX_NUM; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= MAX_NUM; j += i)
      prime[j] = false;
  }
  while (scanf("%d%d", &n, &x), n) {
    for (int i = 0; i < n; i++)
      scanf("%d", &a[i]);
    sort(a, a + n);
    fill_n(dp, x+1, false);
    dp[0] = true;
    for (int i = 1; i <= x; i++) {
      for (int j = 0; j < n && i >= a[j]; j++) {
        if (dp[i - a[j]]) {
          dp[i] = true;
          break;
        }
      }
    }
    int i;
    for (i = x; i >= 0; i--) {
      if (dp[i] && prime[i]) {
        printf("%d\n", i);
        break;
      }
    }
    if(i < 0) printf("NA\n");
  }
}