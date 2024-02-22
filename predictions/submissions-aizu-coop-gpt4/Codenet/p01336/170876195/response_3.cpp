#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }
typedef long long ll;
typedef pair<int, int> pint;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m;
int dpru(int *c, int *v) {
  int dp[333][333];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      int temp = dp[i][j];
      dp[i + 1][j] = temp;
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
  return dp[n][m];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  while (scanf("%d %d", &n, &m) != EOF) {
    int c[333], v[3][333];
    rep(i, n) {
      string s;
      int t;
      cin.ignore();
      getline(cin, s);
      scanf("%d", &t);
      c[i] = t;
      rep(j, 3) scanf("%d", &v[j][i]);
    }
    int res = 0;
    rep(i, 3) max_swap(res, dpru(c, v[i]));
    printf("%d\n", res);
  }
}