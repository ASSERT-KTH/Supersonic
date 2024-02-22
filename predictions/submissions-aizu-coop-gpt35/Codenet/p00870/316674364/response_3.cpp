#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll po[1000];

void solve() {
  int n, m;
  cin >> n >> m;

  vector<ll> ha(n);
  vector<int> len(n);
  for (int i = 0; i < n; ++i) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char c : a)
      h = h * 31 + c;
    ha[i] = h;
  }

  po[0] = 1;
  for (int i = 0; i < 999; ++i)
    po[i + 1] = po[i] * 31;

  int ans = 0;
  int text_len = 0;
  for (int jjj = 0; jjj < m; ++jjj) {
    string a;
    cin >> a;
    text_len += a.size();

    vector<ll> gha(text_len + 1);
    for (int i = 0; i < a.size(); ++i)
      gha[i + 1] = gha[i] * 31 + a[i];

    vector<bool> vis(1 << n, false);
    vector<int> dp(1 << n, 0);
    vis[0] = true;

    for (int j = 0; j < text_len; ++j) {
      int cur = j % 250;
      fill(dp.begin(), dp.end(), 0);

      for (int i = 0; i < (1 << n); ++i) {
        if (!vis[i])
          continue;
        for (int k = 0; k < n; ++k) {
          if (((~i) & (1 << k)) && len[k] + j <= text_len &&
              ha[k] == gha[j + len[k]] - gha[j] * po[len[k]]) {
            dp[i | (1 << k)] = 1;
          }
        }
      }

      ans += dp[(1 << n) - 1];
      vis = dp;
      fill(vis.begin(), vis.end(), false);
      vis[0] = true;
    }
  }

  cout << ans << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  while (cin >> n >> m, n)
    solve();
    
  return 0;
}