#include <iostream>
#include <set>
#include <vector>
#define EPS 1e-10
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

using namespace std;

struct P {
  int x, y;
  P(int x = 0, int y = 0) : x(x), y(y) {}
  P operator+(const P& p) const { return P(x + p.x, y + p.y); }
  P operator-(const P& p) const { return P(x - p.x, y - p.y); }
  P operator*(const P& p) const { return P(x * p.x, y * p.y); }
  P operator/(const P& p) const { return P(x / p.x, y / p.y); }
  bool operator==(const P& p) const {
    return (x == p.x && y == p.y);
  }
  bool operator<(const P& p) const {
    return (x != p.x) ? x < p.x : y < p.y;
  }
};

typedef pair<P, P> Segment;

double cross(const P& a, const P& b) {
  return a.x * b.y - a.y * b.x;
}

int ccw(const P& p, const P& q, const P& r) {
  P a = q - p;
  P b = r - p;
  double cross_product = cross(a, b);
  if (cross_product > EPS)
    return COUNTER_CLOCKWISE;
  if (cross_product < -EPS)
    return CLOCKWISE;
  if (a.x * b.x + a.y * b.y < -EPS)
    return ONLINE_BACK;
  if (a.x * a.x + a.y * a.y < b.x * b.x + b.y * b.y)
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(const P& p1, const P& p2, const P& p3, const P& p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

P crosspoint(const P& p1, const P& p2, const P& p3, const P& p4) {
  int A = cross(p2 - p1, p4 - p3);
  int B = cross(p2 - p1, p2 - p3);
  P pro = p4 - p3;
  pro.x = pro.x * (B / A);
  pro.y = pro.y * (B / A);
  return p3 + pro;
}

int main() {
  int n, xx, yy, xxx, yyy, field;
  vector<Segment> pos;
  Segment pesh;
  set<P> exist;
  P xp;
  while (cin >> n && n) {
    field = 1;
    pos.clear();
    pos.reserve(n);
    for (int i = 0; i < n; i++) {
      cin >> xx >> yy >> xxx >> yyy;
      pesh.first.x = xx;
      pesh.first.y = yy;
      pesh.second.x = xxx;
      pesh.second.y = yyy;
      pos.push_back(pesh);
      int x_counter = 0;
      bool new_x = true;
      exist.clear();
      int size = pos.size() - 1;
      for (int i = 0; i < size; i++) {
        new_x = true;
        if (isIntersect(pos[i].first, pos[i].second, pos[size].first,
                        pos[size].second)) {
          xp = crosspoint(pos[i].first, pos[i].second, pos[size].first,
                          pos[size].second);
          if (100 - abs(xp.x) < EPS || 100 - abs(xp.y) < EPS)
            continue;
          if (exist.count(xp) > 0) {
            new_x = false;
          }
          if (new_x) {
            x_counter++;
            exist.insert(xp);
          }
        }
      }
      field += x_counter + 1;
    }
    cout << field << endl;
  }
  return 0;
}