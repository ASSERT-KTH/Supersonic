#include <iostream>
#include <string>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long ll;
using namespace std;

const int MAXN = 250;
const int MAXM = 6000;
const int MOD = 31;
const int MAX_BIT = 1 << 12;
const int MAX_TEXT = 1000;

ll gha[MAXM];
ll po[MAX_TEXT];
bool vis[MAXN][MAX_BIT];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<ll> ha(n);
  vector<int> len(n);
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char c : a)
      h = h * MOD + c;
    ha[i] = h;
  }
  po[0] = 1;
  rep(i, MAX_TEXT - 1) po[i + 1] = po[i] * MOD;
  int ans = 0;
  string text;
  rep(j, m) {
    string a;
    cin >> a;
    text += a;
  }
  rep(i, text.size()) gha[i + 1] = gha[i] * MOD + text[i];
  rep(i, MAXN) rep(j, MAX_BIT) vis[i][j] = false;
  rep(i, MAXN) vis[i][0] = true;
  rep(j, text.size() + 1) {
    int cur = j % MAXN;
    rep(i, MAX_BIT) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if (!(i & (1 << k)) && len[k] + j <= text.size() &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % MAXN][i | (1 << k)] = true;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, MAX_BIT) vis[cur][i] = false;
    vis[cur][0] = true;
  }
  cout << ans << endl;
}

int main() {
  int n, m;
  while (cin >> n >> m, n)
    solve();
  return 0;
}