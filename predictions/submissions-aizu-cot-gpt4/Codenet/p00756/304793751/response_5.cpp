#include <iostream>
#include <vector>
using namespace std;
constexpr int MAX = 24;
int x[MAX], y[MAX], r[MAX], c[MAX];
vector<bool> memo;

bool ok(const int a, const int bit, const int x[], const int y[], const int r[]) {
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

int dfs(int bit, const int n, const int x[], const int y[], const int r[], const int c[], vector<bool>& memo) {
  memo[bit] = true;
  int ret = n;
  for (int i = 0; i < n; i++)
    if ((bit >> i) & 1)
      ret--;
  for (int i = 0; i < n; i++) {
    if (((bit >> i) & 1) == 0 || !ok(i, bit, x, y, r))
      continue;
    for (int j = i + 1; j < n; j++) {
      if (((bit >> j) & 1) == 0 || c[i] != c[j])
        continue;
      int to_bit = (bit ^ (1 << i)) ^ (1 << j);
      if (ok(j, bit, x, y, r) && !memo[to_bit]) {
        int temp = dfs(to_bit, n, x, y, r, c, memo);
        ret = ret > temp ? ret : temp;  // instead of max()
      }
    }
  }
  return ret;
}

void solve(const int n, const int x[], const int y[], const int r[], const int c[], vector<bool>& memo) {
  memo.assign((1 << n), false);
  cout << dfs((1 << n) - 1, n, x, y, r, c, memo) << endl;
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  while (cin >> n && n) {
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> r[i] >> c[i];
    solve(n, x, y, r, c, memo);
  }
  return 0;
}