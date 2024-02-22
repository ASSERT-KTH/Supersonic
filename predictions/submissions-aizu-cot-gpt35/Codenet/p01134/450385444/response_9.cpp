#include <iostream>
#include <vector>

#define EPS 1e-10

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef std::pair<P, P> Segment;

double cross(const P& a, const P& b) {
  return a.x * b.y - a.y * b.x;
}

int ccw(const P& p, const P& q, const P& r) {
  double crossProduct = cross(q - p, r - p);
  if (crossProduct > EPS) return 1;
  if (crossProduct < -EPS) return -1;
  if ((q - p).x * (r - p).x < -EPS || (q - p).y * (r - p).y < -EPS) return 2;
  if ((q - p).x * (q - p).x + (q - p).y * (q - p).y < (r - p).x * (r - p).x + (r - p).y * (r - p).y) return -2;
  return 0;
}

bool isIntersect(const P& p1, const P& p2, const P& p3, const P& p4) {
  return ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0;
}

P crosspoint(const P& p1, const P& p2, const P& p3, const P& p4) {
  double A = cross(p2 - p1, p4 - p3);
  P pro = p4 - p3;
  pro.x *= A;
  pro.y *= A;
  return p3 + pro;
}

int main() {
  int n;
  while (std::cin >> n && n) {
    int field = 1;
    std::vector<Segment> pos(n);
    for (int i = 0; i < n; i++) {
      std::cin >> pos[i].first.x >> pos[i].first.y >> pos[i].second.x >> pos[i].second.y;
      int x_counter = 0;
      std::vector<P> exist;
      for (int j = 0; j < i; j++) {
        if (isIntersect(pos[j].first, pos[j].second, pos[i].first, pos[i].second)) {
          P xp = crosspoint(pos[j].first, pos[j].second, pos[i].first, pos[i].second);
          bool new_x = true;
          for (int k = 0; k < exist.size(); k++) {
            if (exist[k].x == xp.x && exist[k].y == xp.y) {
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