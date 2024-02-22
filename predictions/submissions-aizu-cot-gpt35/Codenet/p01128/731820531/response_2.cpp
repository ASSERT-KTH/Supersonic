#include <algorithm>
#include <cmath>
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
  double d1 = (seg1.second.x - seg1.first.x) * (seg2.first.y - seg1.first.y) -
              (seg1.second.y - seg1.first.y) * (seg2.first.x - seg1.first.x);
  double d2 = (seg1.second.x - seg1.first.x) * (seg2.second.y - seg1.first.y) -
              (seg1.second.y - seg1.first.y) * (seg2.second.x - seg1.first.x);
  double d3 = (seg2.second.x - seg2.first.x) * (seg1.first.y - seg2.first.y) -
              (seg2.second.y - seg2.first.y) * (seg1.first.x - seg2.first.x);
  double d4 = (seg2.second.x - seg2.first.x) * (seg1.second.y - seg2.first.y) -
              (seg2.second.y - seg2.first.y) * (seg1.second.x - seg2.first.x);

  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
      ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
    return true;
  }
  if (d1 == 0 && on_segment(seg1.first, seg1.second, seg2.first)) {
    return true;
  }
  if (d2 == 0 && on_segment(seg1.first, seg1.second, seg2.second)) {
    return true;
  }
  if (d3 == 0 && on_segment(seg2.first, seg2.second, seg1.first)) {
    return true;
  }
  if (d4 == 0 && on_segment(seg2.first, seg2.second, seg1.second)) {
    return true;
  }
  return false;
}

bool on_segment(const Point &p, const Point &q, const Point &r) {
  if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) &&
      q.y >= min(p.y, r.y)) {
    return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

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
        Point ip = get_intersection_point(s, t);
        c.push_back(make_pair(ip, (o ^ l)));
      }
    }
    sort(c.begin(), c.end());