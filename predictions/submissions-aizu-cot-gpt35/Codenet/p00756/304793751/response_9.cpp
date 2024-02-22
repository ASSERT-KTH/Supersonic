#include <iostream>
#include <bitset>
using namespace std;

const int MAX_N = 24;
int n;
int x[MAX_N], y[MAX_N], r[MAX_N], c[MAX_N];
bitset<(1 << MAX_N)> memo;
int squaredRadius[MAX_N];

bool ok(int a, int bit) {
  for (int i = 0; i < a; i++) {
    if (!(bit & (1 << i)))
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    if (dist < squaredRadius[i] + squaredRadius[a])
      return false;
  }
  return true;
}

int dfs(int bit) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0, b = 1; i < n; i++, b <<= 1)
    if (bit & b)
      ret--;
  for (int i = 0, b = 1; i < n; i++, b <<= 1) {
    if (!(bit & b) || !ok(i, bit))
      continue;
    for (int j = i + 1, c = b << 1; j < n; j++, c <<= 1) {
      if (!(bit & c) || c[i] != c[j])
        continue;
      int to_bit = bit ^ b ^ c;
      if (ok(j, bit) && !memo[to_bit]) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }
  return ret;
}

void solve() {
  memo.reset();
  cout << dfs((1 << n) - 1) << endl;
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  for (int i = 0; i < n; i++)
    squaredRadius[i] = r[i] * r[i];
  return true;
}

int main() {
  while (input())
    solve();
  return 0;
}