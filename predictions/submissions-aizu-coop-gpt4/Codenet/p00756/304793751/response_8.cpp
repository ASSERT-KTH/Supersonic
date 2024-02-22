#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAXN = 24;
int n;
int x[MAXN], y[MAXN], r[MAXN], c[MAXN];
bool memo[1 << MAXN];
bool overlap[MAXN][MAXN];

bool isSet(int bit, int i) {
  return (bit >> i) & 1;
}

void setBit(int &bit, int i, bool value) {
  if (value) {
    bit |= (1 << i);
  } else {
    bit &= ~(1 << i);
  }
}

void precomputeOverlap() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int dist = (x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j]);
      int sum = (r[i] + r[j]) * (r[i] + r[j]);
      overlap[i][j] = dist < sum;
    }
  }
}

int dfs(int bit) {
  if (memo[bit]) {
    return __builtin_popcount(bit);
  }

  int ret = n;
  for (int i = 0; i < n; i++) {
    if (!isSet(bit, i) || overlap[i][i])
      continue;
    for (int j = i + 1; j < n; j++) {
      if (!isSet(bit, j) || c[i] != c[j])
        continue;
      int to_bit = bit;
      setBit(to_bit, i, false);
      setBit(to_bit, j, false);
      if (!overlap[i][j] && !overlap[j][j]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }

  memo[bit] = true;
  return ret;
}

void solve() {
  fill_n(memo, 1 << n, false);
  precomputeOverlap();
  cout << dfs((1 << n) - 1) << endl;
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
  while (input())
    solve();
  return 0;
}