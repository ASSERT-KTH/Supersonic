#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define REP(i, k, n) for (int i = k; i < n; i++)
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
  REP(i, 1, n + 1) {
    int a, b;
    cin >> a >> b;
    v[b - 1].push_back(a);
  }
  REP(i, 1, n + 1) {
    sort(v[i].begin(), v[i].end(), greater<int>());
  }
  memset(d, 0, sizeof(d));
  vector<P> p;
  REP(i, 1, n + 1) {
    REP(k, 1, v[i].size() + 1) {
      d[i][k] += d[i][k - 1] + v[i][k - 1] + (k - 1) * 2;
      p.push_back(mp(k, d[i][k]));
    }
  }
  memset(dp, 0, sizeof(dp));
  REP(i, 1, n + 1) {
    REP(j, 1, K + 1) {
      for (int k = j; k >= 0; k--) {
        if (j >= k) {
          dp[i][j] = max(dp[i][j], dp[i][j - k] + d[i][k]);
        }
      }
    }
  }
  cout << dp[n][K] << endl;
  return 0;
}