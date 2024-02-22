#include <algorithm>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(), (c).end()
#define mp make_pair
typedef complex<double> Point;
typedef pair<int, int> pint;
const double PI = acos(-1.0);
const double EPS = 1e-9;
struct Line { Point first, second; };

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    Line s;
    cin >> s.first >> s.second;
    Point rota(1, -arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    vector<pair<Point, bool>> c;
    int n;
    cin >> n;
    rep(i, n) {
      Line t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (abs(cross(s.second - s.first, t.first - s.first) *
                  cross(s.second - s.first, t.second - s.first)) <
              EPS &&
          (abs(s.first - t.first) + abs(t.first - s.second) <
           abs(s.first - s.second) + EPS))
        c.pb(mp(t.first + ((abs(cross(s.second - s.first, t.first - s.first)) /
                            (abs(cross(s.second - s.first, t.first - s.first)) +
                             abs(cross(s.second - s.first, t.second - s.first)))) *
                           (t.second - t.first)),
               (o ^ l)));
    }
    sort(all(c));
    int res = 0;
    rep(i, (int)c.size() - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}