#include <bits/stdc++.h>
#define MAXN 24
using namespace std;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
bool memo[1 << MAXN];
int dp[MAXN][1 << MAXN];

bool ok(int a, int bit) {
  if(dp[a][bit] != -1) 
    return dp[a][bit];
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return dp[a][bit] = false;
  }
  return dp[a][bit] = true;
}

int dfs(int bit, int ret) {
  if(memo[bit]) 
    return ret;
  memo[bit] = true;
  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1)
      ret--;
    if (((bit >> i) & 1) == 0 || !ok(i, bit))
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit, ret));
      }
    }
  }
  return ret;
}

void solve() {
  fill_n(memo, 1 << n, false);
  printf("%d\n", dfs((1 << n) - 1, n));
}

bool input() {
  scanf("%d", &n);
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    scanf("%d %d %d %d", &x[i], &y[i], &r[i], &c[i]);
  return true;
}

int main() {
  memset(dp, -1, sizeof(dp));
  while (input())
    solve();
  return 0;
}