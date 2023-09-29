#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
using vl = vector<ll>;
using mat = vector<vl>;
const ll mod = 1000000009;
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  rep(i, n) rep(k, n) {
    if (A[i][k])
      rep(j, n)(C[i][j] += A[i][k] * B[k][j]) %= mod;
  }
  return C;
}
mat mat_pow(const mat &A, ll x) {
  int n = A.size();
  mat ret(n, vl(n));
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
vl mul(const mat &A, const vl &b) {
  int n = A.size();
  vl ret(n);
  rep(i, n) {
    if (b[i])
      rep(j, n)(ret[i] += A[i][j] * b[j]) %= mod;
  }
  return ret;
}
int main() {
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
        obj[y].emplace_back(x);
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
      ll Y = p.first;
      if (Y - ny > 1) {
        A = mul(mat_pow(O, Y - ny - 1), A);
      }
      mat B(O);
      for (int i : p.second) {
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
    vl b(w);
    b[0] = 1;
    vl res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}