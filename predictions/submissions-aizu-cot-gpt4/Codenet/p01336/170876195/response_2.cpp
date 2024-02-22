#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }

int n, m;

int dpru(int *c, int **v) {
  int **dp = new int*[n+1];
  for(int i = 0; i <= n; i++)
    dp[i] = new int[m+1];

  CLEAR(dp, 0);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= c[i]) {
        int temp = dp[i + 1][j - c[i]] + v[i];
        max_swap(dp[i + 1][j], temp);
      }
    }
  }
  int res = dp[n][m];

  for(int i = 0; i <= n; i++)
    delete [] dp[i];
  delete [] dp;

  return res;
}

int main() {
  while (cin >> n >> m) {
    int *c = new int[n];
    int **v = new int*[3];
    for(int i = 0; i < 3; i++)
      v[i] = new int[n];
    
    rep(i, n) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      rep(j, 3) cin >> v[j][i];
    }
    int res = 0;
    rep(i, 3) max_swap(res, dpru(c, v[i]));
    cout << res << endl;

    delete [] c;
    for(int i = 0; i < 3; i++)
      delete [] v[i];
    delete [] v;
  }
}