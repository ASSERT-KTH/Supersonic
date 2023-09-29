#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(a) (int)((a).size())
#define CLR(a) memset((a), 0, sizeof(a))

ll po[1000];
ll ha[12];
ll gha[6000];
int len[12];
int n, m;
bool vis[250][1 << 12];

void solve() {
  CLR(ha);
  CLR(len);
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    for(char c : a)
      h = h * 31 + c;
    ha[i] = h;
  }
  
  int ans = 0;
  string text;
  rep(jjj, m) {
    string a;
    cin >> a;
    text += a;
  }

  rep(i, SZ(text))
    gha[i + 1] = gha[i] * 31 + text[i];

  CLR(vis);
  rep(i, 250) vis[i][0] = 1;
  
  rep(j, SZ(text) + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i]) continue;
      rep(k, n) 
        if (!(i & (1 << k)) && len[k] + j <= SZ(text) && ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    CLR(vis[cur]);
    vis[cur][0] = 1;
  }
  cout << ans << endl;
}

int main() {
  po[0] = 1;
  rep(i, 999) po[i + 1] = po[i] * 31;
  while (cin >> n >> m, n)
    solve();
  return 0;
}