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
  vector<int> id;
  vector<vector<int>> v(2005);
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id.push_back(b - 1);
    v[b - 1].push_back(a);
  }
  sort(id.begin(), id.end());
  id.erase(unique(id.begin(), id.end()), id.end());
  int id_size = id.size();
  rep(i, id_size) {
    int j = id[i];
    sort(v[j].begin(), v[j].end(), greater<int>());
  }
  memset(d, 0, sizeof(d));
  vector<P> p;
  rep(i, id_size) {
    int j = id[i];
    int v_size = v[j].size();
    REP(k, 1, v_size + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  rep(i, id_size) {
    rep(j, K + 1) {
      vector<ll> resarr;
      int v_size = v[id[i]].size();
      rep(k, v_size + 1) {
        if (j >= k) {
          resarr.push_back(dp[i][j - k] + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = *max_element(resarr.begin(), resarr.end());
    }
  }
  cout << dp[id_size][K] << endl;
  return 0;
}