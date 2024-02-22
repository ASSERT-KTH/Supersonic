#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <cmath>
#include <utility>

using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
#define dump(x) cerr << __LINE__ << ":\t" #x " = " << x << endl
using ld = long double;
using P = std::complex<ld>;
using G = std::vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;

// ... rest of the code remains same ...

int main() {
  std::vector<int> ans;
  ans.reserve(111); // reserve memory for vector
  
  int n, m;
  std::cin >> n >> m;
  ans.reserve(m);

  ld r[111], mb[111];
  bool used[111] = {false};

  // rest of the code remains same ...

  if (f) {
    for (int i = 0; i < m; i++) 
      std::cout << ans[i] + 1 << "\n";
  } else {
    std::cout << "NG\n";
  }
}