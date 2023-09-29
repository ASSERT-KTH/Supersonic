#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>

#define EPS 1e-10

struct P {
  double x, y;

  P(double x = 0, double y = 0) : x(x), y(y) {}

  P operator+(P p) const { return P(x + p.x, y + p.y); }
  P operator-(P p) const { return P(x - p.x, y - p.y); }

  bool operator==(const P &p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
};

struct pair_hash {
  size_t operator () (const P &p) const {
    auto h1 = std::hash<double>{}(p.x);
    auto h2 = std::hash<double>{}(p.y);
    return h1 ^ h2;
  }
};

using Segment = std::pair<P, P>;

double cross(P a, P b) { return a.x * b.y - a.y * b.x; }
double norm(P p) { return p.x * p.x + p.y * p.y; }

int ccw(P p, P q, P r) {
  P a = q - p;
  P b = r - p;
  if (cross(a, b) > EPS)
    return 1;
  if (cross(a, b) < -EPS)
    return -1;
  if ((a.x * b.x < -EPS) || (norm(a) < norm(b)))
    return -2;
  return 0;
}

bool isIntersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(P p1, P p2, P p3, P p4) {
  double A = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  return P(p3.x + (p4.x - p3.x) * (B / A), p3.y + (p4.y - p3.y) * (B / A));
}

int main() {
  int n;
  Segment pesh;
  P xp;

  while (std::cin >> n && n) {
    int field = 1;
    std::vector<Segment> pos;
    std::unordered_set<P, pair_hash> exist;

    for (int i = 0; i < n; i++) {
      std::cin >> pesh.first.x >> pesh.first.y >> pesh.second.x >> pesh.second.y;
      pos.push_back(pesh);
      int x_counter = 0;

      for (int i = 0; i < pos.size() - 1; i++) {
        if (isIntersect(pos[i].first, pos[i].second, pos.back().first, pos.back().second)) {
          xp = crosspoint(pos[i].first, pos[i].second, pos.back().first, pos.back().second);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS)
            continue;

          if (exist.insert(xp).second) {
            x_counter++;
          }
        }
      }
      field += x_counter + 1;
    }
    std::cout << field << '\n';
  }
  return 0;
}