#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

ll d[15][2005], dp[2005][2005];

int main() {
  int n, K;
  cin >> n >> K;

  vector<vector<int>> v(2005);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    v[b - 1].push_back(a);
  }

  rep(i, 2005) {
    if (!v[i].empty()) {
      sort(v[i].rbegin(), v[i].rend());
    }
  }

  memset(d, 0, sizeof(d));

  rep(i, 2005) {
    if (!v[i].empty()) {
      REP(k, 1, v[i].size() + 1) {
        d[i][k] += d[i][k - 1] + v[i][k - 1] + (k - 1) * 2;
      }
    }
  }

  memset(dp, 0, sizeof(dp));

  rep(i, 2005) {
    if (!v[i].empty()) {
      rep(j, K + 1) {
        ll res = dp[i][j];
        rep(k, v[i].size() + 1) {
          if (j >= k) {
            res = max(res, dp[i][j - k] + d[i][k]);
          }
        }
        dp[i + 1][j] = res;
      }
    }
  }

  cout << dp[2005][K] << endl;

  return 0;
}