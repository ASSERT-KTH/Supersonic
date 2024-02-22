#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#define REP(i, k, n) for (int i = k; i < n; i++)
#define rep(i, n) for (int i = 0; i < n; i++)
#define INF 1 << 30
#define pb push_back
#define mp make_pair
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
ll d[15][2005], dp[2005][2005];
int v[2005][2005], v_size[2005];
int main() {
  int n, K;
  cin >> n >> K;
  int id[2005], id_size = 0;
  rep(i, n) {
    int a, b;
    cin >> a >> b;
    id[id_size++] = b - 1;
    v[b - 1][v_size[b - 1]++] = a;
  }
  sort(id, id + id_size);
  id_size = unique(id, id + id_size) - id;
  rep(i, id_size) {
    int j = id[i];
    sort(v[j], v[j] + v_size[j], greater<int>());
  }
  memset(d, 0, sizeof(d));
  vector<P> p; p.reserve(2005);
  rep(i, id_size) {
    int j = id[i];
    REP(k, 1, v_size[j] + 1) {
      d[j][k] += d[j][k - 1] + v[j][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[j][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  rep(i, id_size) {
    rep(j, K + 1) {
      ll res = dp[i][j];
      ll temp;
      rep(k, v_size[id[i]] + 1) {
        if (j >= k) {
          temp = dp[i][j - k];
          res = max(res, temp + d[id[i]][k]);
        }
      }
      dp[i + 1][j] = res;
    }
  }
  cout << dp[id_size][K] << endl;
  return 0;
}