#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include <complex>
#include <cmath>

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(c) begin(c), end(c)
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
const ld pi = acos(-1);
const ld eps = 1e-10;
const ld inf = 1e12;
ld cross(const P &a, const P &b) {
  return a.real() * b.imag() - a.imag() * b.real();
}
ld dot(const P &a, const P &b) {
  return a.real() * b.real() + a.imag() * b.imag();
}
using C = pair<ld, P>;
#define rad first
#define pnt second

// Refactored smallest_enclosing_disc function

// other helper functions...

bool chk(int s, const vector<int>& b, vector<ld>& a) {
  int last = -1;
  rep(i, a.size()) {
    auto it = upper_bound(b.begin(), b.end(), a[i] - eps);
    if (it == b.end())
      return false;
    last = distance(b.begin(), it);
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;
  vector<int> ans, r(n), used(n, false);
  vector<ld> mb(m);
  vector<int> b;
  rep(i, n) {
    cin >> r[i];
    b.emplace_back(r[i]);
  }
  sort(all(b));
  rep(i, m) {
    int k;
    cin >> k;
    G g(k);
    rep(j, k) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }
  bool f = true;
  rep(i, m) {
    bool found = false;
    rep(j, n) {
      if (used[j])
        continue;
      if (!(mb[i] < r[j] + eps))
        continue;
      used[j] = true;
      vector<ld> a(mb.begin() + i + 1, mb.end());
      sort(all(a));
      if (chk(i + 1, b, a)) {
        ans.push_back(j);
        found = true;
        break;
      }
      used[j] = false;
    }
    if (!found) {
      f = false;
      break;
    }
  }
  if (f) {
    rep(i, m) cout << ans[i] + 1 << "\n";
  } else {
    cout << "NG\n";
  }
}