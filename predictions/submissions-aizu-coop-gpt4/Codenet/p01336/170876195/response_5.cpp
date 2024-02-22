#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;

typedef pair<int, int> pint;
typedef long long ll;
map<pint, ll> memo;

ll dpru(int *c, int *v, int n, int m) {
  if (memo.count({n, m})) return memo[{n, m}];

  int dp_cur[333] = {0}, dp_prev[333] = {0};
  for (int i = 0; i < n; ++i) {
    swap(dp_cur, dp_prev);
    memcpy(dp_cur, dp_prev, sizeof(dp_prev));
    for (int j = c[i]; j <= m; ++j)
      dp_cur[j] = max(dp_cur[j], dp_prev[j - c[i]] + v[i]);
  }
  return memo[{n, m}] = dp_cur[m];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  while (cin >> n >> m) {
    memo.clear();
    int c[333], v[3][333];
    for (int i = 0; i < n; ++i) {
      string s;
      int t;
      getline(cin, s);
      getline(cin, s);
      cin >> t;
      c[i] = t;
      for (int j = 0; j < 3; ++j) 
        cin >> v[j][i];
    }
    ll res = 0;
    for (int i = 0; i < 3; ++i) 
      res = max(res, dpru(c, v[i], n, m));
    cout << res << "\n";
  }
  return 0;
}