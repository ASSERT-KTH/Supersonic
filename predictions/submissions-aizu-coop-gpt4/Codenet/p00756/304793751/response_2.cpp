// rest of the includes
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solver {
  int n;
  vector<int> x, y, r, c;
  vector<bool> memo;

  bool ok(int a, int bit) {
    for (int i = 0; i < a; i++)
      if (((bit >> i) & 1) && ((x[i] - x[a]) * (x[i] - x[a]) + (y[i] - y[a]) * (y[i] - y[a]) < (r[i] + r[a]) * (r[i] + r[a])))
        return false;
    return true;
  }

  int dfs(int bit) {
    memo[bit] = true;
    int ret = __builtin_popcount(bit); // number of set bits in bit
    for (int i = 0; i < n; i++) {
      if (!((bit >> i) & 1) || !ok(i, bit))
        continue;
      for (int j = i + 1; j < n; j++) {
        if (!((bit >> j) & 1) || c[i] != c[j])
          continue;
        int to_bit = bit ^ (1 << i) ^ (1 << j);
        if (ok(j, bit) && !memo[to_bit]) {
          ret = max(ret, dfs(to_bit));
        }
      }
    }
    return ret;
  }

public:
  Solver(int n, vector<int> x, vector<int> y, vector<int> r, vector<int> c) : n(n), x(x), y(y), r(r), c(c), memo(1 << n, false) {}

  void solve() {
    cout << dfs((1 << n) - 1) << endl;
  }
};

int main() {
  int n;
  while (cin >> n && n) {
    vector<int> x(n), y(n), r(n), c(n);
    for (int i = 0; i < n; i++)
      cin >> x[i] >> y[i] >> r[i] >> c[i];
    Solver solver(n, x, y, r, c);
    solver.solve();
  }
  return 0;
}