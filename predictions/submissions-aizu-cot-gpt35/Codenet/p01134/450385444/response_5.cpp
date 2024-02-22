#include <iostream>
#include <vector>
#include <cmath>

#define EPS 1e-10
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
};

typedef std::pair<P, P> Segment;

double cross(P a, P b) {
  return a.x * b.y - a.y * b.x;
}

int ccw(P p, P q, P r) {
  P a = q - p;
  P b = r - p;
  double crossProduct = cross(a, b);
  if (crossProduct > EPS)
    return COUNTER_CLOCKWISE;
  if (crossProduct < -EPS)
    return CLOCKWISE;
  if ((a.x * b.x < -EPS) || (a.y * b.y < -EPS))
    return ONLINE_BACK;
  if (norm(a) < norm(b) - EPS)
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(P p1, P p2, P p3, P p4) {
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
  P pesh;
  std::vector<P> exist;
  P xp;
  while (std::cin >> n && n) {
    field = 1;
    pos.clear();
    for (int i = 0; i < n; i++) {
      std::cin >> xx >> yy >> xxx >> yyy;
      pesh.x = xx;
      pesh.y = yy;
      pesh.x = xxx;
      pesh.y = yyy;
      pos.push_back(pesh);
      int x_counter = 0;
      bool new_x = true;
      exist.clear();
      int posSize = pos.size();
      for (int i = 0; i < posSize - 1; i++) {
        new_x = true;
        if (isIntersect(pos[i].first, pos[i].second, pos[posSize - 1].first,
                        pos[posSize - 1].second)) {
          xp = crosspoint(pos[i].first, pos[i].second, pos[posSize - 1].first,
                          pos[posSize - 1].second);
          if (100 - std::fabs(xp.x) < EPS || 100 - std::fabs(xp.y) < EPS)
            continue;
          int existSize = exist.size();
          for (int j = 0; j < existSize; j++) {
            if (exist[j] == xp) {
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