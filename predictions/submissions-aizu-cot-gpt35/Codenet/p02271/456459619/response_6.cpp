#include <iostream>
using namespace std;

bool solve(int* N, int n, int i, int m, bool** memo) {
  if (i == n) {
    return m == 0;
  }
  
  if (memo[i][m] != -1) {
    return memo[i][m];
  }
  
  bool res = solve(N, n, i + 1, m - N[i], memo) || solve(N, n, i + 1, m, memo);
  memo[i][m] = res;
  return res;
}

int main() {
  int n;
  cin >> n;
  int N[n];
  for (int i = 0; i < n; i++) {
    cin >> N[i];
  }
  
  int t;
  cin >> t;
  
  bool** memo = new bool*[n];
  for (int i = 0; i < n; i++) {
    memo[i] = new bool[t + 1];
    memset(memo[i], -1, sizeof(bool) * (t + 1));
  }
  
  for (int i = 0; i < t; i++) {
    int p;
    cin >> p;
    if (solve(N, n, 0, p, memo)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  
  for (int i = 0; i < n; i++) {
    delete[] memo[i];
  }
  delete[] memo;
}