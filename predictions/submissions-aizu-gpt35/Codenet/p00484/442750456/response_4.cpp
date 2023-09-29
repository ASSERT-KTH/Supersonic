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
ll d[15][2005], dp[2][2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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
  memset(d, 0, sizeof(d));
  vector<P> p;
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.pb(mp(k, d[j][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  int cur = 0, nxt = 1;
  rep(i, id.size()) {
    rep(j, K + 1) {
      dp[nxt][j] = dp[cur][j];
      rep(k, v[id[i]].size() + 1) {
        if (j >= k) {
          dp[nxt][j] = max(dp[nxt][j], dp[cur][j - k] + d[id[i]][k]);
        }
      }
    }
    swap(cur, nxt);
  }
  cout << dp[cur][K] << endl;
  return 0;
}