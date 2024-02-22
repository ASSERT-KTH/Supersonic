#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define pb push_back
#define fi first
#define se second
const ll mod = 1000000009;
using vl = vector<ll>;
using mat = vector<vl>;
mat C;
vl ret;
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  C.assign(n, vl(n));
  rep(i, n) rep(j, n) for(int k = 0; k < n; k += 2) {
    (C[i][j] += (k < n ? A[i][k] * B[k][j] : 0) + (k + 1 < n ? A[i][k+1] * B[k+1][j] : 0)) %= mod;
  }
  return C;
}
mat mat_pow(const mat &A, ll x) {
  int n = A.size();
  ret.assign(n, vl(n));
  rep(i, n) ret[i][i] = 1;
  mat P(A);
  while (x) {
    if (x & 1)
      ret = mul(ret, P);
    P = mul(P, P);
    x >>= 1;
  }
  return ret;
}
vl ret2;
vl mul(const mat &A, const vl &b) {
  int n = A.size();
  ret2.assign(n, 0);
  rep(i, n) rep(j, n)(ret2[i] += A[i][j] * b[j]) %= mod;
  return ret2;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  int w, n;
  ll h;
  while (cin >> w >> h >> n, w) {
    map<ll, vector<int>> obj;
    rep(i, n) {
      ll x, y;
      cin >> x >> y;
      --x;
      --y;
      if (y > 0) {
        obj[y].pb(x);
      }
    }
    mat O(w, vl(w));
    rep(i, w) {
      for (int j = -1; j <= 1; ++j) {
        if (0 <= i + j && i + j < w)
          O[i][i + j] = 1;
      }
    }
    mat A(w, vl(w));
    rep(i, w) A[i][i] = 1;
    ll ny = 0;
    for (const auto &p : obj) {
      ll Y = p.fi;
      if (Y - ny > 1) {
        A = mul(mat_pow(O, Y - ny - 1), A);
      }
      mat B(O);
      for (int i : p.se) {
        for (int j = -1; j <= 1; ++j) {
          if (0 <= i + j && i + j < w)
            B[i][i + j] = 0;
        }
      }
      A = mul(B, A);
      ny = Y;
    }
    if (ny != h - 1)
      A = mul(mat_pow(O, h - 1 - ny), A);
    vector<ll> b(w);
    b[0] = 1;
    vector<ll> res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}