#include <iostream>
#include <vector>
#include <map>

const long long mod = 1000000009;

std::vector<std::vector<long long>> mul(const std::vector<std::vector<long long>>& A, const std::vector<std::vector<long long>>& B) {
  int n = A.size();
  std::vector<std::vector<long long>> C(n, std::vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < n; ++k) {
        C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % mod;
      }
    }
  }
  return C;
}

std::vector<std::vector<long long>> mat_pow(const std::vector<std::vector<long long>>& A, long long x) {
  int n = A.size();
  std::vector<std::vector<long long>> ret(n, std::vector<long long>(n));
  for (int i = 0; i < n; ++i) {
    ret[i][i] = 1;
  }
  std::vector<std::vector<long long>> P(A);
  while (x) {
    if (x & 1) {
      ret = mul(ret, P);
    }
    P = mul(P, P);
    x >>= 1;
  }
  return ret;
}

std::vector<long long> mul(const std::vector<std::vector<long long>>& A, const std::vector<long long>& b) {
  int n = A.size();
  std::vector<long long> ret(n);
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
  long long h;
  while (std::cin >> w >> h >> n && w) {
    std::map<long long, std::vector<int>> obj;
    for (int i = 0; i < n; ++i) {
      long long x, y;
      std::cin >> x >> y;
      --x;
      --y;
      if (y > 0) {
        obj[y].push_back(x);
      }
    }
    std::vector<std::vector<long long>> O(w, std::vector<long long>(w));
    for (int i = 0; i < w; ++i) {
      for (int j = -1; j <= 1; ++j) {
        if (0 <= i + j && i + j < w) {
          O[i][i + j] = 1;
        }
      }
    }
    std::vector<std::vector<long long>> A(w, std::vector<long long>(w));
    for (int i = 0; i < w; ++i) {
      A[i][i] = 1;
    }
    long long ny = 0;
    for (const auto& p : obj) {
      long long Y = p.first;
      if (Y > ny + 1) {
        A = mul(mat_pow(O, Y - ny - 1), A);
      }
      std::vector<std::vector<long long>> B(O);
      for (int i : p.second) {
        for (int j = -1; j <= 1; ++j) {
          if (0 <= i + j && i + j < w) {
            B[i][i + j] = 0;
          }
        }
      }
      A = mul(B, A);
      ny = Y;
    }
    if (ny != h - 1) {
      A = mul(mat_pow(O, h - 1 - ny), A);
    }
    std::vector<long long> b(w);
    b[0] = 1;
    std::vector<long long> res = mul(A, b);
    long long ans = res[w - 1];
    printf("Case %d: %lld\n", T++, ans);
  }
  return 0;
}