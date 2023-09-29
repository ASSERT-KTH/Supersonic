#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define fi first
#define se second
using ll = long long;
using P = pair<int, int>;
using T = tuple<int, int, int>;

const double EPS = 1e-9;
const double PI = acos(-1);

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  double abs() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};
using Vector = Point;
using Line = pair<Point, Point>;

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
bool isOrthogonal(Vector a, Vector b) {
  return fabs(dot(a, b)) < EPS;
}
bool isOrthogonal(Point a1, Point a2, Point b1, Point b2) {
  return isOrthogonal(a1 - a2, b1 - b2);
}
bool isParallel(Vector a, Vector b) {
  return fabs(cross(a, b)) < EPS;
}
bool isParallel(Point a1, Point a2, Point b1, Point b2) {
  return isParallel(a1 - a2, b1 - b2);
}
Point project(Line l, Point p) {
  Vector base = l.second - l.first;
  double r = dot(p - l.first, base) / base.norm();
  return l.first + base * r;
}

Point reflect(Line l, Point p) { return p + (project(l, p) - p) * 2; }

double distanceLP(Line l, Point p) {
  return (p - project(l, p)).abs();
}
double distanceLL(Line l, Line m) {
  if (isParallel(l, m)) return distanceLP(l, m.first);
  return 0;
}
double distanceLS(Line l, Line s) {
  if (cross(l.second - l.first, s.second - s.first) > EPS) swap(s.first, s.second);
  double d1 = cross(l.second - l.first, s.first - l.first);
  double d2 = cross(l.second - l.first, s.second - l.first);
  if (d1 * d2 < EPS) return 0;
  return min({distanceLP(l, s.first), distanceLP(l, s.second),
              distanceLP(s, l.first), distanceLP(s, l.second)});
}
double distanceSP(Line s, Point p) {
  Point r = project(s, p);
  if (isOrthogonal(s.first, s.second, r, p)) return (r - p).abs();
  return min((s.first - p).abs(), (s.second - p).abs());
}
double distanceSS(Line s, Line t) {
  if (isParallel(s, t)) return distanceLS(s, t);
  double d1 = cross(s.second - s.first, t.first - s.first);
  double d2 = cross(s.second - s.first, t.second - s.first);
  double d3 = cross(t.second - t.first, s.first - t.first);
  double d4 = cross(t.second - t.first, s.second - t.first);
  if (d1 * d2 < EPS && d3 * d4 < EPS) return 0;
  return min({distanceSP(s, t.first), distanceSP(s, t.second),
              distanceSP(t, s.first), distanceSP(t, s.second)});
}

bool intersectSS(Line s, Line t) {
  return distanceSS(s, t) < EPS;
}

Point crosspoint(Line l, Line m) {
  double A = cross(l.second - l.first, m.second - m.first);
  double B = cross(l.second - l.first, l.second - m.first);
  if (abs(A) < EPS && abs(B) < EPS) return m.first;
  if (abs(A) >= EPS) return m.first + (m.second - m.first) * (B / A);
  return Point(0, 0);
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<Line> ls(n);
    rep(i, n) {
      double x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      ls[i] = make_pair(Point(x1, y1), Point(x2, y2));
    }

    set<Point> ans;
    rep(i, n) {
      rep(j, i) {
        if (intersectSS(ls[i], ls[j])) {
          ans.insert(crosspoint(ls[i], ls[j]));
        }
      }
    }
    if (ans.empty()) puts("None");
    else if