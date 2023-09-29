#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)

template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }

int n, m;
int c[333], v[3][333], dp[334][334];

int dpru(int *c, int *v) {
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = m; j >= 0; --j) {
      if (j >= c[i])
        max_swap(dp[j], dp[j - c[i]] + v[i]);
    }
  }
  return dp[m];
}

int main() {
  ios::sync_with_stdio(false); 
  cin.tie(0);
  
  while (cin >> n >> m) {
    int res = 0;
    rep(i, n) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      rep(j, 3) cin >> v[j][i];
    }
    rep(i, 3) max_swap(res, dpru(c, v[i]));
    cout << res << "\n";
  }
}