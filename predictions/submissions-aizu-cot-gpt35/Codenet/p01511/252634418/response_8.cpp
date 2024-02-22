#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

const ll mod = 1000000009;

using vl = vector<ll>;
using mat = vector<vl>;

mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return C;
}

mat mat_pow(const mat &A, ll x) {
  int n = A.size();
  mat ret(n, vl(n, 0));
  for (int i = 0; i < n; ++i) {
    ret[i][i] = 1;
  }
  mat P(A);
  while (x) {
    if (x & 1) {
      ret = mul(ret, P);
    }
    P = mul(P, P);
    x >>= 1;
  }
  return ret;
}

vl mul(const mat &A, const vl &b) {
  int n = A.size();
  vl ret(n, 0);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      ret[i] = (ret[i] + A[i][j] * b[j]) % mod;
    }
  }
  return ret;
}

int main() {
  int T = 1;
  int w, n;
  ll h;
  while (cin >> w >> h >> n, w) {
    vector<vector<int>> obj(h, vector<int>());
    for (int i = 0; i < n; ++i) {
      ll x, y;
      cin >> x >> y;
      --x;
      --y;
      if (y > 0) {
        obj[y].push_back(x);
      }
    }
    mat O(w, vl(w, 0));
    for (int i = 0; i < w; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (0 <= i + j && i + j < w) {
          O[i][i + j] = 1;
        }
      }
    }
    mat A(w, vl(w, 0));
    for (int i = 0; i < w; ++i) {
      A[i][i] = 1;
    }
    ll ny = 0;
    for (int i = 0; i < h; ++i) {
      if (obj[i].size() > 0) {
        ll Y = i;
        if (Y - ny > 1) {
          A = mul(mat_pow(O, Y - ny - 1), A);
        }
        mat B(O);
        for (int j : obj[i]) {
          for (int k = -1; k <= 1; ++k) {
            if (0 <= j + k && j + k < w) {
              B[j][j + k] = 0;
            }
          }
        }
        A = mul(B, A);
        ny = Y;
      }
    }
    if (ny != h - 1) {
      A = mul(mat_pow(O, h - 1 - ny), A);
    }
    vl b(w, 0);
    b[0] = 1;
    vl res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}