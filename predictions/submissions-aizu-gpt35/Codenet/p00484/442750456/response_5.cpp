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
ll d[15][2005], dp[2005][2005];
int main() {
  int n, K;
  cin >> n >> K;
  vector<int> id, v[2005];
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
  vector<P> p;
  ll res;
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  sort(p.begin(), p.end(), [](auto &left, auto &right) {
    return left.second > right.second;
  });
  ll sum = 0;
  rep(i, K) {
    sum += p[i].second;
  }
  memset(dp, 0, sizeof(dp));
  res = 0;
  rep(i, id.size()) {
    rep(j, K + 1) {
      dp[i + 1][j] = max(dp[i + 1][j], dp[i][j]);
      if (j + v[id[i]].size() <= K) {
        dp[i + 1][j + v[id[i]].size()] =
            max(dp[i + 1][j + v[id[i]].size()], dp[i][j] + d[id[i]][v[id[i]].size()]);
      }
      if (j + p.size() <= K) {
        dp[i + 1][j + p.size()] = max(dp[i + 1][j + p.size()], res + sum);
      }
    }
    res = max(res, dp[i][K]);
    sum -= p[i].second;
  }
  cout << res << endl;
  return 0;
}