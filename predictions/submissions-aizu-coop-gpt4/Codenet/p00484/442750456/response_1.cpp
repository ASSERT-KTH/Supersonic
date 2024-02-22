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
  set<int> idSet; // use set instead of vector
  vector<int> v[2005];
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    idSet.insert(b - 1); // insert into set
    v[b - 1].push_back(a);
  }
  // convert set to vector
  vector<int> id(idSet.begin(), idSet.end());
  
  for (auto &i : id) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  memset(d, 0, sizeof(d));
  vector<P> p;
  for (auto &j : id) {
    REP(k, 1, v[j].size() + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  rep(i, id.size()) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      int idSize = v[id[i]].size() + 1; // avoid repeated computation
      rep(k, idSize) {
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