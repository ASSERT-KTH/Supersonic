#include <iostream>
#include <algorithm>
#include <random>
#include <complex>
#include <vector>
#include <cmath>
#include <chrono>
using std::vector;
using std::complex;
using std::pair;
using std::cout;
using std::cin;
using std::endl;
using ld = long double;
using P = complex<ld>;
using C = pair<ld, P>;
const ld pi = std::acos((ld)-1);
const ld eps = 1e-10;
ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}

C smallest_enclosing_disc(vector<P> ps) {
  ...
  unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
  std::shuffle(ps.begin(), ps.end(), std::default_random_engine(seed));
  ...
}

int main() {
  int n, m;
  ld r[111], mb[111];
  bool used[111];
  ...
  vector<int> ans;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> r[i];
  for (int i = 0; i < m; i++) {
    int k;
    cin >> k;
    G g(k);
    for (int j = 0; j < k; j++) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }
  for (int i = 0; i < m; i++) used[i] = false;
  ...
  if (f) {
    for (int i = 0; i < m; i++) cout << ans[i] + 1 << "\n";
  } else {
    cout << "NG" << endl;
  }
}