#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; ++i)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define INF 1 << 30
#define pb emplace_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[15][2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id, v[2005];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id.pb(b - 1);
    v[b - 1].pb(a);
  }
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  rep(i, id.size()) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
  }
  fill_n(&d[0][0], 15*2005, 0);
  vector<P> p;
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.pb(mp(k, d[j][k]));
    }
  }
  fill_n(&dp[0][0], 2005*2005, 0);
  rep(i, id.size()) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, v[id[i]].size() + 1) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[id.size()][K] << endl;
  return 0;
}