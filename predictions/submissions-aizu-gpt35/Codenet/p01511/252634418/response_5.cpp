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

// Optimized mul function for two matrices
void mul(mat &A, const mat &B) {
  int n = A.size();
  rep(i, n) {
    rep(j, n) {
      ll sum = 0;
      rep(k, n) {
        sum += A[i][k] * B[k][j];
        sum %= mod;
      }
      A[i][j] = sum;
    }
  }
}

// Optimized mat_pow function for a matrix and an exponent
void mat_pow(mat &A, ll x) {
  int n = A.size();
  mat ret(n, vl(n));
  rep(i, n) ret[i][i] = 1;
  mat P(A); // Copy of A
  while (x) {
    if (x & 1) mul(ret, P);
    mul(P, P);
    x >>= 1;
  }
  A = ret;
}

// Optimized mul function for a matrix and a vector
void mul(const mat &A, const vl &b, vl &res) {
  int n = A.size();
  rep(i, n) {
    ll sum = 0;
    rep(j, n) {
      sum += A[i][j] * b[j];
      sum %= mod;
    }
    res[i] = sum;
  }
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
        obj[y].pb(x);
      }
    }
    mat O(w, vl(w));
    rep(i, w) {
      for (int j = -1; j <= 1; ++j) {
        if (0 <= i + j && i + j < w) O[i][i + j] = 1;
      }
    }
    mat A(w, vl(w));
    rep(i, w) A[i][i] = 1;
    ll ny = 0;
    for (const auto &p : obj) {
      ll Y = p.fi;
      if (Y - ny > 1) mat_pow(O, Y - ny - 1), mul(A, O);
      mat B(O);
      for (int i : p.se) {
        for (int j = -1; j <= 1; ++j) {
          if (0 <= i + j && i + j < w) B[i][i + j] = 0;
        }
      }
      mul(A, B);
      ny = Y;
    }
    if (ny != h - 1) mat_pow(O, h - 1 - ny), mul(A, O);
    vector<ll> b(w);
    b[0] = 1;
    vector<ll> res(w);
    mul(A, b, res);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}