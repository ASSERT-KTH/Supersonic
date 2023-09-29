#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(), (a).end()

ll gha[6000];
bool vis[1 << 12][100];
ll po[1000];
int n, m;

void solve() {
  ll ha[n];
  int len[n];
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    for (char c : a)
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
  bool vis[250][1 << n];
  rep(i, 250) rep(j, 1 << n) vis[i][j] = 0;
  rep(i, 250) vis[i][0] = 1;
  rep(j, SZ(text) + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if (!(i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  cout << ans << endl;
}

int main() {
  while (cin >> n >> m, n)
    solve();
  return 0;
}