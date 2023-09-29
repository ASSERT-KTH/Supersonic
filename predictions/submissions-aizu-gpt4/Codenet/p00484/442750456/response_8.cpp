#include <algorithm>
#include <cstring>
#include <iostream>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define INF 1 << 30
using namespace std;
typedef long long ll;
ll d[2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> v[2005];
  REP(i, 1, n + 1) {
    int a, b;
    cin >> a >> b;
    v[b - 1].push_back(a);
  }
  REP(i, 1, n + 1) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  memset(d, 0, sizeof(d));
  REP(i, 1, n + 1) {
    REP(k, 1, v[i].size() + 1) {
      d[k] += d[k - 1] + v[i][k - 1] + (k - 1) * 2;
    }
  }
  memset(dp, 0, sizeof(dp));
  REP(i, 1, n + 1) {
    REP(j, 1, K + 1) {
      ll res = dp[i - 1][j];
      REP(k, 1, v[i].size() + 1) {
        if (j >= k) {
          res = max(res, dp[i - 1][j - k] + d[k]);
        }
      }
      dp[i][j] = res;
    }
  }
  cout << dp[n][K] << endl;
  return 0;
}