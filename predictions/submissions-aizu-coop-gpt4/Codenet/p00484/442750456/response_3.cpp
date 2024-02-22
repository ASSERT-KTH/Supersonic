#include <algorithm>
#include <cstring>
#include <iostream>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[2005][2005], dp[2005][2005];
int id[2005], v[2005][2005];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, K;
  cin >> n >> K;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id[i] = b - 1;
    v[b - 1][i] = a;
  }
  sort(id, id + n);
  rep(i, n) {
    int j = id[i];
    sort(v[j], v[j] + n, greater<int>());
  }
  memset(d, 0, sizeof(d));
  rep(i, n) {
    int j = id[i];
    REP(k, 1, n + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
    } 
  }
  memset(dp, 0, sizeof(dp));
  rep(i, n) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, n + 1) {
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