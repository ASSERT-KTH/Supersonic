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

// Optimized matrix multiplication function
mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  mat BT(n, vl(n));
  rep(i, n) rep(j, n) BT[i][j] = B[j][i]; // Transposing B for efficient access
  rep(i, n) rep(j, n) {
    ll t = 0;
    rep(k, n) t = (t + A[i][k] * BT[j][k]) % mod;
    C[i][j] = t;
  }
  return C;
}

// Fast Matrix exponentiation function
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
  rep(i, n) rep(j, n)(ret[i] += A[i][j] * b[j]) %= mod;
  return ret;
}

// Rest of the main function remains the same