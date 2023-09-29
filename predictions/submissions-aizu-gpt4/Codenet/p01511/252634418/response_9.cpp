#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;
const ll mod = 1000000009;
using mat = vector<vector<ll>>;
mat operator*(const mat &A, const mat &B) {
  mat C(A.size(), vector<ll>(B[0].size()));
  for (int i = 0; i < A.size(); ++i) 
    for (int k = 0; k < B.size(); ++k) 
      for (int j = 0; j < B[0].size(); ++j) 
        C[i][j] = (C[i][j] + A[i][k] * B[k][j] % mod) % mod;
  return C;
}
mat pow(const mat &A, ll x) {
  mat B(A.size(), vector<ll>(A.size()));
  for (int i = 0; i < A.size(); ++i) B[i][i] = 1;
  mat P = A;
  while (x > 0) {
    if (x & 1) B = B*P;
    P = P*P;
    x >>= 1;
  }
  return B;
}
int main() {
  int T = 1;
  int w, n;
  ll h;
  while (cin >> w >> h >> n, w) {
    map<ll, vector<int>> obj;
    for (int i = 0; i < n; ++i) {
      ll x, y;
      cin >> x >> y;
      --x;
      --y;
      if (y > 0) {
        obj[y].push_back(x);
      }
    }
    mat O(w, vector<ll>(w));
    for (int i = 0; i < w; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (i + j >= 0 && i + j < w)
          O[i][i + j] = 1;
      }
    }
    mat A(w, vector<ll>(w));
    for (int i = 0; i < w; ++i) A[i][i] = 1;
    ll ny = 0;
    for (const auto &p : obj) {
      ll Y = p.first;
      if (Y - ny > 1) {
        A = pow(O, Y - ny - 1)*A;
      }
      mat B = O;
      for (int i : p.second) {
        for (int j = -1; j <= 1; ++j) {
          if (i + j >= 0 && i + j < w)
            B[i][i + j] = 0;
        }
      }
      A = B*A;
      ny = Y;
    }
    if (ny != h - 1)
      A = pow(O, h - 1 - ny)*A;
    vector<ll> b(w);
    b[0] = 1;
    vector<ll> res = A*vector<vector<ll>>(w, vector<ll>(1, 1));
    ll ans = res[w - 1][0];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}