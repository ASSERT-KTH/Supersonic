#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using P = complex<ld>;
using G = vector<P>;
using C = pair<ld, P>;
#define rad first
#define pnt second

// ... rest of the code is the same ...

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  
  vector<int> b;
  rep(i, n) {
    cin >> r[i];
    if (!used[i]) b.emplace_back(r[i]);
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
  
  rep(i, m) used[i] = false;
  bool f = true;
  
  rep(i, m) {
    bool found = false;
    rep(j, n) {
      if (used[j])
        continue;
      if (!(mb[i] < r[j] + eps))
        continue;
      used[j] = true;
      if (chk(i + 1, b)) { // pass b by reference to chk function
        cout << j + 1 << "\n";
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
  
  if (!f) {
    cout << "NG" << endl;
  }
}