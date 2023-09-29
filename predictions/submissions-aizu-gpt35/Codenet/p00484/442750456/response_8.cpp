#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>

#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30

using namespace std;

typedef long long ll;

const int MAXN = 2005, MAXK = 2005;

ll d[MAXN][15], dp[MAXN][MAXK];

int main() {
  int n, K;
  cin >> n >> K;

  vector<int> id, v[MAXN];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }

  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());

  rep(i, id.size()) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
  }

  memset(d, 0, sizeof(d));

  vector<pair<int, ll>> p;
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.emplace_back(k, d[j][k]);
    }
  }

  memset(dp, 0, sizeof(dp));
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