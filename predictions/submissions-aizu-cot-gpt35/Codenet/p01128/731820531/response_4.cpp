#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point {
  double x, y;
};

struct Line {
  Point first, second;
};

bool intersect_SS(const Line &seg1, const Line &seg2) {
  double dir1 = (seg1.second.x - seg1.first.x) * (seg2.first.y - seg1.first.y) - (seg1.second.y - seg1.first.y) * (seg2.first.x - seg1.first.x);
  double dir2 = (seg1.second.x - seg1.first.x) * (seg2.second.y - seg1.first.y) - (seg1.second.y - seg1.first.y) * (seg2.second.x - seg1.first.x);
  double dir3 = (seg2.second.x - seg2.first.x) * (seg1.first.y - seg2.first.y) - (seg2.second.y - seg2.first.y) * (seg1.first.x - seg2.first.x);
  double dir4 = (seg2.second.x - seg2.first.x) * (seg1.second.y - seg2.first.y) - (seg2.second.y - seg2.first.y) * (seg1.second.x - seg2.first.x);
  return (dir1 * dir2 < 0) && (dir3 * dir4 < 0);
}

int main() {
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
      if (intersect_SS(s, t))
        c.push_back(make_pair(Point(), (o ^ l)));
    }
    sort(c.begin(), c.end(), [](const pair<Point, bool>& a, const pair<Point, bool>& b) {
      return a.first.x < b.first.x;
    });
    int res = 0;
    for (int i = 0; i < c.size() - 1; ++i) {
      if (c[i].second != c[i + 1].second) {
        ++res;
      }
    }
    cout << res << endl;
  }
}