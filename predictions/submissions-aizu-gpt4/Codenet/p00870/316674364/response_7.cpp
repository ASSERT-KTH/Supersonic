#include <iostream>
#include <vector>
#include <string>
#include <queue>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(a) (int)((a).size())
typedef long long ll;

using namespace std;

int n, m;
ll gha[6000];
ll po[1000];

void solve() {
  vector<ll> ha(n);
  vector<int> len(n);
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    for(char c : a)
      h = h * 31 + c;
    ha[i] = h;
  }
  po[0] = 1;
  rep(i, 999) po[i + 1] = po[i] * 31;
  int ans = 0;
  string text;
  rep(jjj, m) {
    string a;
    cin >> a;
    text += a;
  }
  rep(i, SZ(text)) gha[i + 1] = gha[i] * 31 + text[i];
  vector<vector<bool>> vis(250, vector<bool>(1<<n, false));
  rep(i, 250) vis[i][0] = true;
  rep(j, SZ(text) + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if (!(i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = true;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) vis[cur][i] = false;
    vis[cur][0] = true;
  }
  cout << ans << endl;
  return;
}

int main() {
  while (cin >> n >> m, n)
    solve();
  return 0;
}