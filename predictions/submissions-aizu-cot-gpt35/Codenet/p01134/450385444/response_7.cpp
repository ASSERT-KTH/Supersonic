#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct P {
  int x, y;
  P(int x = 0, int y = 0) : x(x), y(y) {}
  P operator+(const P& p) const { return P(x + p.x, y + p.y); }
  P operator-(const P& p) const { return P(x - p.x, y - p.y); }
  bool operator==(const P& p) const { return (x == p.x && y == p.y); }
  bool operator<(const P& p) const { return (x != p.x ? x < p.x : y < p.y); }
};

typedef pair<P, P> Segment;

int ccw(const P& p, const P& q, const P& r) {
  int cross_product = (q.x - p.x) * (r.y - p.y) - (r.x - p.x) * (q.y - p.y);
  return (cross_product > 0) - (cross_product < 0);
}

bool isIntersect(const P& p1, const P& p2, const P& p3, const P& p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(const P& p1, const P& p2, const P& p3, const P& p4) {
  int cross_product = (p2.x - p1.x) * (p4.y - p3.y) - (p4.x - p3.x) * (p2.y - p1.y);
  P pro = p4 - p3;
  pro.x = pro.x * ((p2.x - p1.x) * (p2.y - p3.y)) / cross_product;
  pro.y = pro.y * ((p2.x - p1.x) * (p2.y - p3.y)) / cross_product;
  return p3 + pro;
}

int main() {
  int n, xx, yy, xxx, yyy, field;
  vector<Segment> pos;
  set<P> exist;
  P xp;
  while (cin >> n && n) {
    field = 1;
    pos.clear();
    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      Segment pesh = make_pair(P(xx, yy), P(xxx, yyy));
      pos.push_back(pesh);
      int x_counter = 0;
      for (int i = 0; i < pos.size() - 1; i++) {
        if (isIntersect(pos[i].first, pos[i].second, pos.back().first, pos.back().second)) {
          xp = crosspoint(pos[i].first, pos[i].second, pos.back().first, pos.back().second);
          if (xp.x == 100 || xp.y == 100)
            continue;
          if (exist.insert(xp).second)
            x_counter++;
        }
      }
      field += x_counter;
    }
    cout << field << endl;
  }
  return 0;
}