#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(), (a).end()
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt, pt> line;
FP dot(P a, P b) { return real(conj(a) * b); }
FP crs(P a, P b) { return imag(conj(a) * b); }
P ortho(P a) { return P(imag(a), -real(a)); }
P ortho(line a) { return ortho(a.S - a.F); }
P crspt(P a, P b, P c, P d) {
  b -= a, d -= c;
  return a + b * crs(d, c - a) / crs(d, b);
}
P crspt(line a, line b) { return crspt(a.F, a.S, b.F, b.S); }
bool onl(P a1, P a2, P b) {
  return abs(b - a1) + abs(b - a2) < abs(a1 - a2) + EPS;
}
bool onl(line a, P b) { return onl(a.F, a.S, b); }
bool iscrs(line a, line b) {
  P c = crspt(a, b);
  return onl(a, c) && onl(b, c);
}
void pkuassert(bool t) { t = 1 / t; };
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
enum { TOP, BTM, LFT, RGT, FRT, BCK };
int dxdy2ce[] = {RGT, FRT, LFT, BCK};
int n, m;
ll gha[6000];
bool vis[1 << 12][100];
ll po[1000];
void solve() {
  ll ha[n];
  int len[n];
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    for (char ch : a)
    h = h * 31 + ch;
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
  memset(vis, 0, sizeof(vis));
  rep(i, 250) vis[i][0] = 1;
  rep(j, SZ(text) + 1) {
    int cur = j % 250;
    rep(i, 1 << n) {
      if (!vis[cur][i])
        continue;
      rep(k, n) if ((~i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    memset(vis[cur], 0, sizeof(vis[cur]));
    vis[cur][0] = 1;
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> n >> m, n)
    solve();
  return 0;
}