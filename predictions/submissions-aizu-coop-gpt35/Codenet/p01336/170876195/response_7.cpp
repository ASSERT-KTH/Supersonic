#include <iostream>
using namespace std;

template <class T> void swap(T &a, const T &b) { T temp = a; a = b; b = temp; }

int dpru(int *c, int **v, int n, int m) {
  int **dp = new int*[n+1];
  for (int i = 0; i <= n; ++i) {
    dp[i] = new int[m+1];
  }
  memset(dp, 0, sizeof(int) * (n + 1) * (m + 1));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i])
        swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i][j]);
    }
  }
  int res = dp[n][m];
  for (int i = 0; i <= n; ++i) {
    delete[] dp[i];
  }
  delete[] dp;
  return res;
}

int main() {
  int n, m;
  while (cin >> n >> m) {
    int *c = new int[n];
    int **v = new int*[3];
    for (int i = 0; i < 3; ++i) {
      v[i] = new int[n];
    }
    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) {
        cin >> v[j][i];
      }
    }
    int res = 0;
    for (int i = 0; i < 3; ++i) {
      swap(res, dpru(c, v, n, m));
    }
    cout << res << endl;
    delete[] c;
    for (int i = 0; i < 3; ++i) {
      delete[] v[i];
    }
    delete[] v;
  }
}