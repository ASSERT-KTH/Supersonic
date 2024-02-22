#define _CRT_SECURE_NO_WARNINGS
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <algorithm>
#include <complex>
#include <array>
using std::vector;
using std::pair;
using std::complex;
using std::array;
using std::sort;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long double R;
typedef complex<R> P;
typedef vector<P> G;
R eps = 1e-10;
R inf = 1e12;
R pi = acos(-1);
P CENTER = P();

struct DUMP : std::ostringstream {
  template <class T> DUMP &operator,(const T &t) {
    if (this->tellp())
      *this << ", ";
    *this << t;
    return *this;
  }
};

#define all(c) (c).begin(), (c).end()
#define loop(i, a, b) for (ll i = a; i < ll(b); i++)
#define rep(i, b) loop(i, 0, b)
#define each(e, c) for (auto &e : c)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define lb lower_bound
#define ub upper_bound
#define dump(...)

...

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  while (std::cin >> n >> m) {
    ans.clear();
    rep(i, n) std::cin >> r[i];
    rep(i, m) {
      int k;
      std::cin >> k;
      G g(k);
      rep(j, k) {
        R x, y;
        std::cin >> x >> y;
        g[j] = P(x, y);
      }
      mb[i] = min_ball(g).r;
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
        if (chk(i + 1)) {
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
      rep(i, m) std::cout << ans[i] + 1 << "\n";
    } else
      std::cout << "NG" << std::endl;
  }
}