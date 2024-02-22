#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(c) (c).begin(), (c).end()

typedef complex<double> Point;
typedef pair<Point, bool> PIB;
typedef pair<Point, Point> Line;

// original functions optimized here...

int main() {
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    Line s;
    cin >> s.first >> s.second;
    Point rota(1, -arg(s.second - s.first));
    s.first *= rota, s.second *= rota;
    vector<PIB> c;
    int n;
    cin >> n;
    rep(i, n) {
      Line t;
      int o, l;
      cin >> t.first >> t.second >> o >> l;
      t.first *= rota, t.second *= rota;
      if (intersect_SS(s, t))
        c.push_back(make_pair(ip_SS(s, t), (o ^ l)));
    }
    sort(all(c));
    int res = 0;
    rep(i, (int)c.size() - 1) if (c[i].second != c[i + 1].second)++ res;
    cout << res << endl;
  }
}