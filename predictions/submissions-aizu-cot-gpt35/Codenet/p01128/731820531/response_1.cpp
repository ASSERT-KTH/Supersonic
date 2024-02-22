#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};

struct Line {
  Point first, second;
};

bool intersect_SS(const Line &seg1, const Line &seg2) {
  double x1 = seg1.first.x, y1 = seg1.first.y;
  double x2 = seg1.second.x, y2 = seg1.second.y;
  double x3 = seg2.first.x, y3 = seg2.first.y;
  double x4 = seg2.second.x, y4 = seg2.second.y;

  double d1 = (x1 - x2) * (y3 - y1) + (y1 - y2) * (x1 - x3);
  double d2 = (x1 - x2) * (y4 - y1) + (y1 - y2) * (x1 - x4);
  double d3 = (x3 - x4) * (y1 - y3) + (y3 - y4) * (x3 - x1);
  double d4 = (x3 - x4) * (y2 - y3) + (y3 - y4) * (x3 - x2);

  return (d1 * d2 < 0) && (d3 * d4 < 0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int T;
  cin >> T;
  while (T--) {
    Line s;
    cin >> s.first.x >> s.first.y >> s.second.x >> s.second.y;

    vector<pair<Point, bool>> c;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      Line t;
      int o, l;
      cin >> t.first.x >> t.first.y >> t.second.x >> t.second.y >> o >> l;

      if (intersect_SS(s, t)) {
        Point ip;
        ip.x = (t.first.x + t.second.x) / 2;
        ip.y = (t.first.y + t.second.y) / 2;
        c.push_back(make_pair(ip, (o ^ l)));
      }
    }

    sort(c.begin(), c.end());
    int res = 0;
    for (int i = 0; i < c.size() - 1; ++i) {
      if (c[i].second != c[i + 1].second) {
        ++res;
      }
    }

    cout << res << '\n';
  }

  return 0;
}