#include <algorithm>
#include <iostream>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[15][2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> v[2005];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    v[b - 1].push_back(a);
  }
  rep(i, 2005) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  rep(i, 2005) {
    REP(k, 1, v[i].size() + 1) {
      d[i][k] += d[i][k - 1] + v[i][k - 1] + (k - 1) * 2;
    }
  }
  rep(i, 2005) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      REP(k, 0, min(j+1, v[i].size() + 1)) {
        res = max(res, dp[i][j - k] + d[i][k]);
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[2005][K] << endl;
  return 0;
}