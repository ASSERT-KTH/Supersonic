#include <iostream>
#include <vector>
using namespace std;

vector<int> N;
int n;
vector<vector<int>> memo;

bool solve(int i, int m) {
  if (i == n) {
    return m == 0;
  }

  if (memo[i][m] != -1) {
    return memo[i][m];
  }

  bool result = solve(i + 1, m - N[i]) || solve(i + 1, m);
  memo[i][m] = result;
  return result;
}

int main() {
  int t;
  cin >> n;
  N.resize(n);
  memo.resize(n, vector<int>(10001, -1));

  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }

  cin >> t;

  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;

    if (solve(0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }

  return 0;
}