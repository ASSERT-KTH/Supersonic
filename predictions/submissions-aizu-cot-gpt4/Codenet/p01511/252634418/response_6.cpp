#include <iostream>
#include <vector>
#include <map>

using ll = long long;
using vl = std::vector<ll>;
using mat = std::vector<vl>;

const ll mod = 1000000009;

mat mul(const mat &A, const mat &B) {
  int n = A.size();
  mat C(n, vl(n));
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          ll temp = 0;
          for(int k=0; k<n; k++){
              temp = (temp + A[i][k]*B[k][j]) % mod;
          }
          C[i][j] = temp;
      }
  }
  return C;
}

mat mat_pow(const mat &A, ll x) {
  int n = A.size();
  mat ret(n, vl(n));
  for(int i=0; i<n; i++) ret[i][i] = 1;
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
  for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
          ret[i] = (ret[i] + A[i][j] * b[j]) % mod;
      }
  }
  return ret;
}

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int T = 1;
  int w, n;
  ll h;
  while (std::cin >> w >> h >> n, w) {
    std::map<ll, std::vector<int>> obj;
    for(int i=0; i<n; i++) {
      ll x, y;
      std::cin >> x >> y;
      --x; --y;
      if (y > 0) {
        obj[y].push_back(x);
      }
    }

    mat O(w, vl(w));
    for(int i=0; i<w; i++) {
      for (int j = -1; j <= 1; ++j) {
        if (0 <= i + j && i + j < w)
          O[i][i + j] = 1;
      }
    }

    mat A(w, vl(w));
    for(int i=0; i<w; i++) A[i][i] = 1;
    
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
    
    vl b(w, 0);
    b[0] = 1;
    
    vl res = mul(A, b);
    ll ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}