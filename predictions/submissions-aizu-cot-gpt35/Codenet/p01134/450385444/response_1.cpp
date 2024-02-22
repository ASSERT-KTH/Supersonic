#include <iostream>
#include <vector>

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef std::pair<P, P> Segment;

double cross(const P& a, const P& b) { return a.x * b.y - a.y * b.x; }

int ccw(const P& p, const P& q, const P& r) {
  P a = q - p;
  P b = r - p;
  double crossProduct = cross(a, b);
  if (crossProduct > 0)
    return 1;
  if (crossProduct < 0)
    return -1;
  if ((a.x * b.x + a.y * b.y) < 0)
    return 2;
  if (a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y)
    return -2;
  return 0;
}

bool isIntersect(const P& p1, const P& p2, const P& p3, const P& p4) {
  int ccw1 = ccw(p1, p2, p3);
  int ccw2 = ccw(p1, p2, p4);
  int ccw3 = ccw(p3, p4, p1);
  int ccw4 = ccw(p3, p4, p2);
  return (ccw1 * ccw2 <= 0 && ccw3 * ccw4 <= 0);
}

P crosspoint(const P& p1, const P& p2, const P& p3, const P& p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  P pro = p4 - p3;
  pro.x = pro.x * (B / A);
  pro.y = pro.y * (B / A);
  return p3 + pro;
}

int main() {
  int n, xx, yy, xxx, yyy, field;
  std::vector<Segment> pos;
  std::vector<P> exist;

  while (std::cin >> n && n) {
    field = 1;
    pos.clear();
    for (int i = 0; i < n; i++) {
      std::cin >> xx >> yy >> xxx >> yyy;
      pos.emplace_back(P(xx, yy), P(xxx, yyy));
      int x_counter = 0;
      exist.clear();
      for (int j = 0; j < pos.size() - 1; j++) {
        if (isIntersect(pos[j].first, pos[j].second, pos.back().first, pos.back().second)) {
          P xp = crosspoint(pos[j].first, pos[j].second, pos.back().first, pos.back().second);
          if (100 - std::abs(xp.x) < 1e-10 || 100 - std::abs(xp.y) < 1e-10)
            continue;
          bool new_x = true;
          for (const P& p : exist) {
            if (p == xp) {
              new_x = false;
              break;
            }
          }
          if (new_x) {
            x_counter++;
            exist.push_back(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    std::cout << field << std::endl;
  }
  return 0;
}