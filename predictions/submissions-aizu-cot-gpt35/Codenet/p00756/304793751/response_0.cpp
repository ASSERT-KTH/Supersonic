#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int n;
vector<int> x, y, r, c;
unordered_set<int> memo;

bool ok(int& a, int& bit) {
  for (int i = 0; i < a; i++) {
    if (((bit >> i) & 1) == 0)
      continue;
    int dist = (x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]);
    int sum = (r[i] + r[a]) * (r[i] + r[a]);
    if (dist < sum)
      return false;
  }
  return true;
}

int dfs(int bit) {
  if (memo.count(bit))
    return n;

  memo.insert(bit);

  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;

  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || ok(i, bit) == false)
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit)) {
        ret = max(ret, dfs(to_bit));
      }
    }
  }

  return ret;
}

void solve() {
  memo.clear();
  cout << dfs((1 << n) - 1) << endl;
}

bool input() {
  cin >> n;
  if (!n)
    return false;
  x.resize(n);
  y.resize(n);
  r.resize(n);
  c.resize(n);
  for (int i = 0; i < n; i++)
    cin >> x[i] >> y[i] >> r[i] >> c[i];
  return true;
}

int main() {
  while (input())
    solve();
  return 0;
}