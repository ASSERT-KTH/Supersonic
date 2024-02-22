#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
using namespace std;

using ld = long double;
using P = complex<ld>;
using G = vector<P>;

const ld eps = 1e-10;

struct C {
  ld rad;
  P pnt;
};

C smallest_enclosing_disc(vector<P> ps) {
  // TODO: Implement a more efficient algorithm to find the smallest enclosing circle
  // ...
}

bool chk(const vector<ld>& a, const vector<ld>& b) {
  vector<ld> sorted_a = a;
  vector<ld> sorted_b = b;
  sort(sorted_a.begin(), sorted_a.end());
  sort(sorted_b.begin(), sorted_b.end());

  int last = -1;
  for (int i = 0; i < sorted_a.size(); ++i) {
    bool found = false;
    for (int j = last + 1; j < sorted_b.size(); ++j) {
      if (sorted_a[i] < sorted_b[j] + eps) {
        found = true;
        last = j;
        break;
      }
    }
    if (!found) {
      return false;
    }
  }
  return true;
}

int main() {
  int n, m;
  cin >> n >> m;

  vector<int> r(n);
  for (int i = 0; i < n; ++i) {
    cin >> r[i];
  }

  vector<ld> mb(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    G g(k);
    for (int j = 0; j < k; ++j) {
      ld x, y;
      cin >> x >> y;
      g[j] = P(x, y);
    }
    mb[i] = smallest_enclosing_disc(g).rad;
  }

  vector<bool> used(n, false);
  vector<int> ans;
  bool f = true;

  for (int i = 0; i < m; ++i) {
    bool found = false;
    for (int j = 0; j < n; ++j) {
      if (used[j] || !(mb[i] < r[j] + eps)) {
        continue;
      }
      used[j] = true;
      if (chk(mb, r)) {
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
    for (int i = 0; i < m; ++i) {
      cout << ans[i] + 1 << "\n";
    }
  } else {
    cout << "NG" << endl;
  }

  return 0;
}