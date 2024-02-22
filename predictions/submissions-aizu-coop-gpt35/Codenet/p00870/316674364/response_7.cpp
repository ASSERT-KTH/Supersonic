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
#define F first
#define S second
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

void solve() {
  int n, m;
  cin >> n >> m;

  ll ha[n];
  int len[n];
  rep(i, n) {
    string a;
    cin >> a;
    ll h = 0;
    len[i] = a.size();
    for (char c : a) {
      h = h * 31 + c;
    }
    ha[i] = h;
  }

  ll gha[m];
  string text;
  rep(jjj, m) {
    string a;
    cin >> a;
    text += a;
  }
  rep(i, m) {
    gha[i + 1] = gha[i] * 31 + text[i];
  }

  int ans = 0;
  int vis[m % 250][1 << n];
  rep(i, m % 250) {
    rep(j, 1 << n) {
      vis[i][j] = 0;
    }
    vis[i][0] = 1;
  }

  rep(j, m + 1) {
    int cur = j % 250;
    rep(k, n) {
      rep(i, 1 << n) {
        if (!vis[cur][i])
          continue;
        if ((~i & (1 << k)) && len[k] + j <= m &&
            ha[k] == gha[j + len[k]] - gha[j] * 31)
          vis[(j + len[k]) % 250][i | (1 << k)] = 1;
      }
    }
    ans += vis[cur][(1 << n) - 1];
    rep(i, 1 << n) {
      vis[cur][i] = 0;
    }
    vis[cur][0] = 1;
  }

  cout << ans << endl;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
