#include <algorithm>
#include <iostream>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[15][2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  int id[2005], v[2005][2005];
  int v_size[2005] = {0};
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id[i] = b - 1;
    v[b - 1][v_size[b - 1]++] = a;
  }
  sort(id, id + n);
  int new_end = unique(id, id + n) - id;
  rep(i, new_end) {
    int j = id[i];
    sort(v[j], v[j] + v_size[j], greater<int>());
  }
  vector<P> p;
  rep(i, new_end) {
    int j = id[i];
    REP(k, 1, v_size[j] + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  rep(i, new_end) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, v_size[id[i]] + 1) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[new_end][K] << endl;
  return 0;
}