#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
#include <complex>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
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

template <class T> ostream &operator<<(ostream &os, vector<T> const &v) {
  rep(i, v.size()) os << v[i] << (i + 1 == (int)v.size() ? "" : " ");
  return os;
}

// ... rest of the code ...

int main() {
#ifdef LOCAL
  freopen("in", "r", stdin);
#endif
  while (cin >> n >> m) {
    ans.clear();
    ans.reserve(m); // preallocate memory for vector
    rep(i, n) cin >> r[i];
    rep(i, m) {
      int k;
      cin >> k;
      G g(k);
      g.reserve(k); // preallocate memory for vector
      rep(j, k) {
        R x, y;
        cin >> x >> y;
        g[j] = P(x, y);
      }
      mb[i] = min_ball(g).r;
    }
    // ... rest of the code ...
  }
}