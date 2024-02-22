#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id, v[2005];
  id.reserve(n);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  memset(d, 0, sizeof(d));
  rep(i, id.size()) {
    int j = id[i];
    ll sum = 0;
    REP(k, 1, v[j].size() + 1) {
      sum += v[j][k - 1] + (k - 1) * 2;
      d[k] = sum;
    }
  }
  memset(dp, 0, sizeof(dp));
  rep(i, id.size()) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, v[id[i]].size() + 1) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[id.size()][K] << endl;
  return 0;
}