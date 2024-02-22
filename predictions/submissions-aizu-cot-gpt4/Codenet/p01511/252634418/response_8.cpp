#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int(i) = 0; (i) < (int)(n); ++(i))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define fi first
#define se second
#define dbg(x) cout << #x " = " << ((x)) << endl
template <class T, class U>
ostream &operator<<(ostream &o, const pair<T, U> &p) {
  o << "(" << p.fi << "," << p.se << ")";
  return o;
}
template <class T> ostream &operator<<(ostream &o, const vector<T> &v) {
  o << "[";
  for (T t : v) {
    o << t << ",";
  }
  o << "]";
  return o;
}
const ll mod = 1000000009;
using vl = vector<ll>;
using mat = vector<vl>;
void mul(mat &C, const mat &A, const mat &B) {
  int n = A.size();
  rep(i, n) rep(j, n) rep(k, n)(C[i][j] += A[i][k] * B[k][j]) %= mod;
}
void mul(vl &ret, const mat &A, const vl &b) {
  int n = A.size();
  rep(i, n) rep(j, n)(ret[i] += A[i][j] * b[j]) %= mod;
}
void mat_pow(mat &ret, const mat &A, ll x) {
  int n = A.size();
  mat P(A);
  while (x) {
    if (x & 1)
      mul(ret, ret, P);
    mul(P, P, P);
    x >>= 1;
  }
}
int main() {
  int T = 1;
  int w, n;
  ll h;
  while (scanf("%d %lld %d", &w, &h, &n), w) {
    map<ll, vector<int>> obj;
    rep(i, n) {
      ll x, y;
      scanf("%lld %lld", &x, &y);
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
    mat temp(w, vl(w));
    for (const auto &p : obj) {
      ll Y = p.fi;
      if (Y - ny > 1) {
        mat_pow(temp, O, Y - ny - 1);
        mul(A, temp, A);
      }
      mat B(O);
      for (int i : p.se) {
        for (int j = -1; j <= 1; ++j) {
          if (0 <= i + j && i + j < w)
            B[i][i + j] = 0;
        }
      }
      mul(A, B, A);
      ny = Y;
    }
    if (ny != h - 1) {
      mat_pow(temp, O, h - 1 - ny);
      mul(A, temp, A);
    }
    vl b(w, 0);
    b[0] = 1;
    vl res(w, 0);
    mul(res, A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}