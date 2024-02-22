#include <algorithm>
#include <cfloat>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
#ifdef _MSC_VER
#define __typeof__ decltype
template <class T> int __builtin_popcount(T n) {
  return n ? 1 + __builtin_popcount(n & (n - 1)) : 0;
}
#endif
#define foreach(it, c)                                                         \
  for (__typeof__((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end()
#define rall(c) (c).rbegin(), (c).rend()
#define CLEAR(arr, val) memset(arr, val, sizeof(arr))
#define rep(i, n) for (int i = 0; i < n; ++i)
template <class T> void max_swap(T &a, const T &b) { a = max(a, b); }
template <class T> void min_swap(T &a, const T &b) { a = min(a, b); }
typedef long long ll;
typedef pair<int, int> pint;
const double PI = acos(-1.0);
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int n, m;
int dp[333][333];
void dpru(int *c, int *v) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      if (j >= c[i])
        max_swap(dp[i + 1][j], dp[i + 1][j - c[i]] + v[i]);
    }
  }
}
int main() {
  while (cin >> n >> m) {
    int c[333], v[3][333];
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
    CLEAR(dp, 0);
    dpru(c, v[0]);
    for(int i=0; i<=m; ++i) max_swap(res, dp[n][i]);
    rep(i, 2) {
      for(int j=0; j<=m; ++j) dp[n][j] = dp[n-1][j];
      dpru(c, v[i+1]);
      for(int j=0; j<=m; ++i) max_swap(res, dp[n][i]);
    }
    cout << res << endl;
  }
}