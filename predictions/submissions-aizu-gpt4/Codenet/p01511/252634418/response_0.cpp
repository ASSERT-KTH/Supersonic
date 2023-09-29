#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> mat;
const ll mod = 1000000009;

inline mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
          for(int k=0; k<n; ++k) 
              C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
  return C;
}

inline mat mat_pow(const mat &A, ll x) {
  int n = A.size();
  mat ret(n, vl(n));
  for(int i=0; i<n; ++i) ret[i][i] = 1;
  mat P(A);
  while (x) {
    if (x & 1)
      ret = mul(ret, P);
    P = mul(P, P);
    x >>= 1;
  }
  return ret;
}

inline vl mul(const mat &A, const vl &b) {
  int n = A.size();
  vl ret(n);
  for(int i=0; i<n; ++i)
      for(int j=0; j<n; ++j)
          ret[i] = (ret[i] + A[i][j] * b[j]) % mod;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int T = 1, w, n;
  ll h;
  while (cin >> w >> h >> n, w) {
    map<ll, vector<int>> obj;
    for(int i=0; i<n; ++i) {
      ll x, y;
      cin >> x >> y;
      --x;
      --y;
      if (y > 0)
        obj[y].push_back(x);
    }
    mat O(w, vl(w));
    for(int i=0; i<w; ++i) {
      for (int j = max(0, i-1); j <= min(w-1, i+1); ++j)
        O[i][j] = 1;
    }
    mat A = O;
    ll ny = 0;
    for (const auto &p : obj) {
      ll Y = p.first;
      if (Y - ny > 1)
        A = mul(mat_pow(A, Y - ny - 1), A);
      mat B = O;
      for (int i : p.second)
        for (int j = max(0, i-1); j <= min(w-1, i+1); ++j)
          B[i][j] = 0;
      A = mul(B, A);
      ny = Y;
    }
    if (ny != h - 1)
      A = mul(mat_pow(A, h - 1 - ny), A);
    vector<ll> b(w, 1);
    vector<ll> res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}