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
// New struct for items
struct Item {
  int cost;
  int value[3];
};
// Return the entire dp array instead of the maximum value
vector<vector<int>> dpru(Item *items) {
  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= m; ++j) {
      dp[i + 1][j] = dp[i][j];
      if (j >= items[i].cost)
        max_swap(dp[i + 1][j], dp[i + 1][j - items[i].cost] + items[i].value[0]);
    }
  }
  return dp;
}
int main() {
  while (cin >> n >> m) {
    Item items[333];
    rep(i, n) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      items[i].cost = t;
      rep(j, 3) cin >> items[i].value[j];
    }
    vector<vector<int>> dp = dpru(items);
    int res = 0;
    // Take the maximum over all dp arrays
    rep(i, n + 1) rep(j, m + 1) rep(k, 3) max_swap(res, dp[i][j] + items[k].value[k]);
    cout << res << endl;
  }
}