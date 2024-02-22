#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
typedef long long ll;
typedef pair<int, int> PI;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP(i, n) rep(i, n)
#define F first
#define S second
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define min3(a, b, c) min((a), min((b), (c)))
#define min4(a, b, c, d) min((a), min3((b), (c), (d)))
#define SZ(a) (int)((a).size())
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) a.rbegin(), a.rend()
#define FLL(a, b) memset((a), b, sizeof(a))
#define CLR(a) memset((a), 0, sizeof(a))
#define declare(a, it) __typeof(a) it = (a)
#define FOR(it, a) for (declare(a.begin(), it); it != a.end(); ++it)
#define FORR(it, a) for (declare(a.rbegin(), it); it != a.rend(); ++it)
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt, pt> line;
namespace std {
bool operator<(const P &a, const P &b) {
  if (abs(a.real() - b.real()) > 1e-6)
    return a.real() < b.real();
  return a.imag() < b.imag();
}
} // namespace std
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
  return abs(b - a1) + abs(b - a2) < abs(a1 - a2) + 1e-6;
}
bool onl(line a, P b) { return onl(a.F, a.S, b); }
bool iscrs(line a, line b) {
  P c = crspt(a, b);
  return onl(a, c) && onl(b, c);
}
void pkuassert(bool t) { t = 1 / t; };
int dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int dy[] = {1, 0, -1, 0, -1, 1, 1, -1};
int dxdy2ce[] = {1, 2, 3, 4};
int s2i(std::string &a) {
  stringstream ss(a);
  int r;
  ss >> r;
  return r;
}
template <class T> T shift(T a, int b, int c, int d, int e) {
  __typeof(a[0]) t = a[b];
  a[b] = a[c];
  a[c] = a[d];
  a[d] = a[e];
  a[e] = t;
  return a;
}
template <class T> T rgt(T a) { return shift(a, 0, 2, 1, 3); }
template <class T> T lft(T a) { return shift(a, 0, 3, 1, 2); }
template <class T> T frt(T a) { return shift(a, 0, 4, 1, 5); }
template <class T> T bck(T a) { return shift(a, 0, 5, 1, 4); }
line mkl(P a, P v) { return line(a, a + v); }
FP lpdist(line a, P b) { return abs(b - crspt(a, mkl(b, ortho(a)))); }
FP spdist(line a, P b) {
  P c(crspt(a, mkl(b, ortho(a))));
  return onl(a, c) ? abs(b - c) : min(abs(a.F - b), abs(a.S - b));
}
FP ssdist(line a, line b) {
  return iscrs(a, b) ? 0.
                     : min4(spdist(a, b.F), spdist(a, b.S), spdist(b, a.F),
                            spdist(b, a.S));
}
int n, m;
ll gha[6000];
bool vis[1 << 12][100];
ll po[1000];
void solve() {
  ll ha[n];
  int len[n];
  rep(i, n) {
    std::string a;
    scanf("%s", &a);
    ll h = 0;
    len[i] = SZ(a);
    FOR(it, a)
    h = h * 31 + *it;
    ha[i] = h;
  }
  po[0] = 1;
  rep(i, 999) po[i + 1] = po[i] * 31;
  int ans = 0;
  std::string text;
  rep(jjj, m) {
    std::string a;
    scanf("%s", &a);
    text += a;
  }
  rep(i, SZ(text)) gha[i + 1] = gha[i] * 31 + text[i];
  CLR(vis);
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
    rep(i, 1 << n) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  printf("%d\n", ans);
  return;
  rep(jjj, m) {
    std::string a;
    scanf("%s", &a);
    rep(i, SZ(a)) gha[i + 1] = gha[i] * 31 + a[i];
    CLR(vis);
    queue<PI> q;
    rep(i, n) rep(j, SZ(a) - len[i] + 1) {
      ll t = gha[j + len[i]] - gha[j] * po[len[i]];
      if (t == ha[i])
        q.push(mp(1 << i, j + len[i]));
    }
    while (!q.empty()) {
      int cst = q.front().F;
      int cp = q.front().S;
      q.pop();
      if (vis[cst][cp])
        continue;
      vis[cst][cp] = 1;
      ans += cst == (1 << n) - 1;
      rep(i, n) {
        if (((~cst) & (1 << i)) &&
            ha[i] == gha[cp + len[i]] - gha[cp] * po[len[i]])
          q.push(mp(cst | (1 << i), cp + len[i]));
      }
    }
  }
  printf("%d\n", ans);
}
int main(int argc, char *argv[]) {
  while (scanf("%d %d", &n, &m), n)
    solve();
  return 0;
}
