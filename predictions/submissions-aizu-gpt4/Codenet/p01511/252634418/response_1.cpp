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
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  rep(i, n) {
      rep(j, n) {
          ll t = 0;
          rep(k, n)
              t = (t + (A[i][k] * B[k][j]) % mod) % mod;
          C[i][j] = t;
      }
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
      ll t = 0;
      rep(j, n)
          t = (t + (A[i][j] * b[j]) % mod) % mod;
      ret[i] = t;
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
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
      for (int j = max(0, i - 1); j <= min(w - 1, i + 1); ++j) {
          O[i][j] = 1;
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
        for (int j = max(0, i - 1); j <= min(w - 1, i + 1); ++j) {
          B[i][j] = 0;
        }
      }
      A = mul(B, A);
      ny = Y;
    }
    if (h - 1 > ny)
      A = mul(mat_pow(O, h - 1 - ny), A);
    vector<ll> b(w, 0);
    b[0] = 1;
    vector<ll> res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}