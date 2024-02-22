#pragma GCC optimize ("Ofast")
#include "bits/stdc++.h"
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
#define EPS (1e-10)
class P {
public:
  double x, y;
  // other methods...
};

// Other structures and functions...

bool isSimple(Polygon pol) {
  size_t pol_size = pol.size() - 1;
  rep(i, pol_size) {
    for (int j = i + 2; j < pol_size; j++) {
      if (i == j || i == (j - 1 + pol_size) % pol_size ||
          i == (j + 1 + pol_size) % pol_size)
        continue;
      if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
        return false;
    }
  }
  return true;
}

// Other functions...

int main() {
  while (cin >> N && N) {
    rep(i, N) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}