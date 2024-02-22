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
static ll d[15][2005], dp[2005][2005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, K;
  cin >> n >> K;
  set<int> idSet;
  vector<int> v[2005];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    idSet.insert(b - 1);
    v[b - 1].push_back(a);
  }
  vector<int> id(idSet.begin(), idSet.end());
  rep(i, id.size()) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
  }
  memset(d, 0, sizeof(d));
  vector<P> p;
  p.reserve(id.size());
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  rep(i, id.size()) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      for (int k = 0; k <= min(j, (int)v[id[i]].size()); k++) {
        res = max(res, dp[i][j - k] + d[id[i]][k]);
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[id.size()][K] << endl;
  return 0;
}