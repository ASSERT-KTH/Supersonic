#include <iostream>
#include <vector>
using namespace std;
vector<int> N;
bool solve(int i, int m, vector<vector<int>>& memo) {
  if (m == 0) return true;
  if (i >= N.size()) return false;
  if (memo[i][m] != -1) return memo[i][m];
  return memo[i][m] = solve(i + 1, m - N[i], memo) || solve(i + 1, m, memo);
}
int main() {
  int n, t;
  cin >> n;
  N.resize(n);
  for (int& x : N) cin >> x;
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    vector<vector<int>> memo(n, vector<int>(p + 1, -1));
    cout << (solve(0, p, memo) ? "yes\n" : "no\n");
  }
}