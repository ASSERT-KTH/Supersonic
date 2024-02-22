#include <iostream>
#include <vector>
using namespace std;

bool solve(const vector<int>& N, int i, int m) {
  if (m == 0)
    return true;
  if (i == N.size())
    return false;
  return solve(N, i + 1, m - N[i]) || solve(N, i + 1, m);
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, t;
  cin >> n;
  vector<int> N(n);
  for (int& num : N) {
    cin >> num;
  }
  cin >> t;
  while (t--) {
    int p;
    cin >> p;
    cout << (solve(N, 0, p) ? "yes" : "no") << endl;
  }
  return 0;
}