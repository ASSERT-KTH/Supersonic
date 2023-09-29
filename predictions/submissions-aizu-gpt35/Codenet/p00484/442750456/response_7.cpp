#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
const int MAX_N = 2005;
ll d[15][MAX_N], dp[MAX_N][MAX_N];
int main() {
  int n, K;
  cin >> n >> K;
  int id[MAX_N], cnt[MAX_N] = {};
  vector<int> v[MAX_N];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id[i] = b - 1;
    v[b - 1].push_back(a);
    cnt[b - 1]++;
  }
  int m = 0;
  rep(i, MAX_N) {
    if (cnt[i] > 0) m++;
  }
  sort(id, id + n);
  n = unique(id, id + n) - id;
  rep(i, n) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
    rep(k, v[j].size() - 1) {
      v[j][k + 1] += v[j][k];
    }
  }
  memset(d, 0, sizeof(d));
  vector<P> p;
  rep(i, n) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  rep(i, n) {
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
  cout << dp[n][K] << endl;
  return 0;
}