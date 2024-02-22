#include <iostream>
#include <vector>
#include <cmath>
#define EPS 1e-10

using namespace std;

struct P {
  double x, y;
  P(double x = 0, double y = 0) : x(x), y(y) {}
  P operator+(const P& p) { return P(x + p.x, y + p.y); }
  P operator-(const P& p) { return P(x - p.x, y - p.y); }
  P operator*(const P& p) { return P(x * p.x, y * p.y); }
  P operator/(const P& p) { return P(x / p.x, y / p.y); }
  bool operator==(const P& p) const {
    return (x == p.x && y == p.y);
  }
  bool operator<(const P& p) const {
    return (x != p.x) ? (x < p.x) : (y < p.y);
  }
};

typedef pair<P, P> Segment;

double dot(const P& a, const P& b) {
  return a.x * b.x + a.y * b.y;
}

double cross(const P& a, const P& b) {
  return a.x * b.y - a.y * b.x;
}

int ccw(const P& p, const P& q, const P& r) {
  double cross_product = cross(q - p, r - p);
  if (cross_product > EPS)
    return 1;
  if (cross_product < -EPS)
    return -1;
  if (dot(q - p, r - p) < -EPS)
    return 2;
  if (dot(q - p, q - p) < dot(r - p, r - p))
    return -2;
  return 0;
}

bool isIntersect(const P& p1, const P& p2, const P& p3, const P& p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 && ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
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
  vector<Segment> pos;
  vector<P> exist;
  P xp;

  while (cin >> n && n) {
    field = 1;
    pos.clear();
    exist.clear();

    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      pos.push_back(Segment(P(xx, yy), P(xxx, yyy)));
      int x_counter = 0;
      bool new_x = true;

      for (int i = 0; i < pos.size() - 1; i++) {
        new_x = true;
        if (isIntersect(pos[i].first, pos[i].second, pos[pos.size() - 1].first, pos[pos.size() - 1].second)) {
          xp = crosspoint(pos[i].first, pos[i].second, pos[pos.size() - 1].first, pos[pos.size() - 1].second);
          if (100 - fabs(xp.x) < EPS || 100 - fabs(xp.y) < EPS)
            continue;
          for (int j = 0; j < exist.size(); j++) {
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
    cout << field << endl;
  }
  return 0;
}