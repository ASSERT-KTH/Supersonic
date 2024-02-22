#include <cmath>
#include <iostream>
#include <unordered_set>
#include <vector>

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  P operator+(P p) { return P(x + p.x, y + p.y); }
  P operator-(P p) { return P(x - p.x, y - p.y); }
  P operator*(P p) { return P(x * p.x, y * p.y); }
  P operator/(P p) { return P(x / p.x, y / p.y); }
  bool operator==(const P &p) const {
    return (std::fabs(x - p.x) < 1e-10 && std::fabs(y - p.y) < 1e-10);
  }
  bool operator<(const P &p) const {
    return x != p.x ? std::fabs(x - p.x) < 1e-10 : std::fabs(y - p.y) < 1e-10;
  }
};

typedef std::pair<P, P> Segment;

double cross(P a, P b) { return a.x * b.y - a.y * b.x; }

bool isIntersect(P p1, P p2, P p3, P p4) {
  return (cross(p2 - p1, p3 - p1) * cross(p2 - p1, p4 - p1) <= 0 &&
          cross(p4 - p3, p1 - p3) * cross(p4 - p3, p2 - p3) <= 0);
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
  int n;
  while (std::cin >> n && n) {
    int field = 1;
    std::vector<Segment> pos;
    std::unordered_set<P> exist;
    Segment pesh;
    P xp;
    for (std::size_t i = 0; i < n; i++) {
      int xx, yy, xxx, yyy;
      std::cin >> xx >> yy >> xxx >> yyy;
      pesh.first.x = xx;
      pesh.first.y = yy;
      pesh.second.x = xxx;
      pesh.second.y = yyy;
      pos.push_back(pesh);

      int x_counter = 0;
      bool new_x = true;
      P last_pos = pos.back().first;

      for (std::size_t j = 0; j < pos.size() - 1; j++) {
        new_x = true;
        if (isIntersect(pos[j].first, pos[j].second, last_pos, pos.back().second)) {
          xp = crosspoint(pos[j].first, pos[j].second, last_pos, pos.back().second);
          double diff_x = 100 - std::fabs(xp.x);
          double diff_y = 100 - std::fabs(xp.y);
          if (diff_x < 1e-10 || diff_y < 1e-10)
            continue;

          if (exist.count(xp) > 0) {
            new_x = false;
          } else {
            x_counter++;
            exist.insert(xp);
          }
        }
      }

      field += x_counter + 1;
    }
    std::cout << field << std::endl;
  }
  return 0;
}