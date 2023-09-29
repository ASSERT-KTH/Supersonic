#include <iostream>
#include <vector>
#include <algorithm>
#define MAXN 24
using namespace std;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
int memo[1 << MAXN];

inline int calcDist(int a, int b){
  return (x[a] - x[b]) * (x[a] - x[b]) + (y[a] - y[b]) * (y[a] - y[b]);
}

inline bool ok(int a, int bit) {
  int dist, sum;
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    dist = calcDist(a, i);
    sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}

int dfs(int bit) {
  if(memo[bit]) return memo[bit];
  int ret = __builtin_popcount(bit);
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || !ok(i, bit))
      continue;
    for (int j = 0; j < n; j++) {
      if (i == j || ((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      ret = max(ret, dfs(bit ^ (1 << i) ^ (1 << j)));
    }
  }
  return memo[bit] = ret;
}

void solve() {
  fill_n(memo, 1 << n, 0);
  cout << dfs((1 << n) - 1) << "\n";
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (input())
    solve();
  return 0;
}