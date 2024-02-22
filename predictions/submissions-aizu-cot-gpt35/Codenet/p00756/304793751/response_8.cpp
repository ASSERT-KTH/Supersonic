#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> x, y, r, c;
vector<bool> memo;

bool ok(int a, int bit) {
  int dist = (x[a] - x[n]) * (x[a] - x[n]) + (y[a] - y[n]) * (y[a] - y[n]);
  int sum = (r[a] + r[n]) * (r[a] + r[n]);
  return dist >= sum;
}

int dfs(int bit) {
  if (memo[bit])
    return n - __builtin_popcount(bit);
  
  memo[bit] = true;
  int ret = n;

  for (int i = 0; i < n; i++) {
    if ((bit >> i) & 1) {
      for (int j = i + 1; j < n; j++) {
        if (((bit >> j) & 1) && c[i] == c[j] && ok(i, bit) && ok(j, bit)) {
          int to_bit = bit ^ (1 << i) ^ (1 << j);
          ret = max(ret, dfs(to_bit));
        }
      }
    }
  }

  return ret;
}

void solve() {
  memo.assign(1 << n, false);
  cout << dfs((1 << n) - 1) << "\n";
}

bool input(vector<int>& x, vector<int>& y, vector<int>& r, vector<int>& c) {
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
  vector<int> x, y, r, c;
  do {
    input(x, y, r, c);
    solve();
  } while (n > 0);
  return 0;
}