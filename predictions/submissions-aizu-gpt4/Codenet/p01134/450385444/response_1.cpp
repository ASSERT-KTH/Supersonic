#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

#define EPS 1e-10
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}

  P operator-(P p) const { return P(x - p.x, y - p.y); }
  bool operator==(const P &p) const { return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS; }
};

typedef std::pair<P, P> Segment;

double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
double dot(P a, P b) { return a.x * b.x + a.y * b.y; }
double norm(P p) { return p.x * p.x + p.y * p.y; }

int ccw(P p, P q, P r) {
  P a = q - p;
  P b = r - p;
  if (cross(a, b) > EPS) return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS) return CLOCKWISE;
  if (dot(a, b) < -EPS) return ONLINE_BACK;
  if (norm(a) < norm(b)) return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(P p1, P p2, P p3, P p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  return P(p3.x + (p4.x - p3.x) * (B / A), p3.y + (p4.y - p3.y) * (B / A));
}

int main() {
  int n;
  while (std::cin >> n && n) {
    int field = 1;
    std::vector<Segment> pos;
    for (int i = 0; i < n; i++) {
      Segment pesh;
      std::cin >> pesh.first.x >> pesh.first.y >> pesh.second.x >> pesh.second.y;
      pos.push_back(pesh);
      std::vector<P> exist;
      int x_counter = 0;
      for (int i = 0; i < int(pos.size()) - 1; i++) {
        if (isIntersect(pos[i].first, pos[i].second, pos.back().first, pos.back().second)) {
          P xp = crosspoint(pos[i].first, pos[i].second, pos.back().first, pos.back().second);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS) continue;
          if (std::find(exist.begin(), exist.end(), xp) == exist.end()) {
            x_counter++;
            exist.push_back(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    std::cout << field << '\n';
  }
  return 0;
}