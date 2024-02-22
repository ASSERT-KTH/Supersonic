#include <algorithm>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
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
  id.reserve(n); // Reserve memory for 'n' elements
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
  fill(&d[0][0], &d[0][0] + sizeof(d) / sizeof(ll), 0); // Replace memset with std::fill
  vector<P> p;
  p.reserve(id.size()); // Reserve memory for 'id.size()' elements
  rep(i, id.size()) {
    int j = id[i];
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(ll), 0); // Replace memset with std::fill
  rep(i, id.size()) {
    ll max_res = 0;
    rep(j, K + 1) {
      ll res = dp[i][j];
      rep(k, v[id[i]].size() + 1) {
        if (j >= k) {
          res = max(res, dp[i][j - k] + d[id[i]][k]);
        }
      }
      max_res = max(max_res, res); // Calculate max incrementally
      dp[i + 1][j] = max_res; // Use the previously calculated max value
    }
  }
  cout << dp[id.size()][K] << endl;
  return 0;
}