#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> PI;
#define EPS (1e-6)
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
template <typename T, typename U>
ostream &operator<<(ostream &out, const pair<T, U> &val) {
  return out << "(" << val.F << ", " << val.S << ")";
}
template <class T> ostream &operator<<(ostream &out, const vector<T> &val) {
  out << "{";
  rep(i, SZ(val)) out << (i ? ", " : "") << val[i];
  return out << "}";
}
typedef double FP;
typedef complex<FP> pt;
typedef pt P;
typedef pair<pt, pt> line;
namespace std {
bool operator<(const P &a, const P &b) {
  if (abs(a.real() - b.real()) > EPS)
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
int s2i(string &a) {
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
template <class T> T rgt(T a) { return shift(a, TOP, LFT, BTM, RGT); }
template <class T> T lft(T a) { return shift(a, TOP, RGT, BTM, LFT); }
template <class T> T frt(T a) { return shift(a, TOP, BCK, BTM, FRT); }
template <class T> T bck(T a) { return shift(a, TOP, FRT, BTM, BCK); }
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
    string a;
    cin >> a;
    ll h = 0;
    len[i] = SZ(a);
    FOR(it, a)
    h = h * 31 + *it;
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
      rep(k, n) if ((~i & (1 << k)) && len[k] + j <= SZ(text) &&
                    ha[k] == gha[j + len[k]] - gha[j] * po[len[k]])
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) vis[cur][i] = 0;
    vis[cur][0] = 1;
  }
  cout << ans << endl;
  return;
  rep(jjj, m) {
    string a;
    cin >> a;
    rep(i, SZ(a)) gha[i + 1] = gha[i] * 31 + a[i];
    rep(i, 1 << n) rep(j, SZ(a) + 1) vis[i][j] = 0;
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
  cout << ans << endl;
}
int main(int argc, char *argv[]) {
  while (cin >> n >> m, n)
    solve();
  return 0;
}
