#include <cmath>
#include <cstdio>
#include <vector>
#include <algorithm>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double a) const { return Point(a * x, a * y); }
  bool operator<(const Point &p) const {
    return x != p.x ? x < p.x : y < p.y;
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

struct Segment {
  Point p1, p2;
  Segment(Point p1 = Point(), Point p2 = Point()) : p1(p1), p2(p2) {}
};

typedef Point Vector;
typedef Segment Line;

double dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
double abs(const Vector &a) { return sqrt(dot(a, a)); }
Vector rotate(const Vector &a, double rad) {
  return Vector(cos(rad) * a.x - sin(rad) * a.y, sin(rad) * a.x + cos(rad) * a.y);
}
Point crosspoint(const Line &l, const Line &m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  if (abs(A) < EPS) {
    return m.p1;
  }
  return m.p1 + (m.p2 - m.p1) * (B / A);
}

void compute(const vector<Line> &lines) {
  vector<Line> candidates;
  for (int i = 0; i < lines.size(); i++) {
    for (int j = i + 1; j < lines.size(); j++) {
      Point cp = crosspoint(lines[i], lines[j]);
      Vector v1 = (lines[i].p1 - cp) / abs(lines[i].p1 - cp);
      Vector v2 = (lines[j].p1 - cp) / abs(lines[j].p1 - cp);
      Vector e = rotate(v1 + v2, M_PI/2);
      candidates.push_back(Line(cp, cp + e * 100));
    }
  }

  vector<Point> candidatePoints;
  for (int i = 0; i < candidates.size(); i++) {
    for (int j = i + 1; j < candidates.size(); j++) {
      candidatePoints.push_back(crosspoint(candidates[i], candidates[j]));
    }
  }

  vector<Point> &v = candidatePoints;
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  for (const Point &p : v) {
    double dist = -1;
    bool success = true;
    for (const Line &line : lines) {
      double tmp = abs(p - crosspoint(line, Line(p, p + Vector(1, 0))));
      if (equals(dist, -1)) {
        dist = tmp;
      } else if (!equals(dist, tmp)) {
        success = false;
        break;
      }
    }
    if (success) {
      printf("%.10f %.10f\n", p.x, p.y);
      return;
    }
  }
  puts("None");
}

int main() {
  int n;
  while (scanf("%d", &n), n) {
    vector<Line> lines(n);
    for (int i = 0; i < n; i++) {
      scanf("%lf%lf%lf%lf", &lines[i].p1.x, &lines[i].p1.y, &lines[i].p2.x, &lines[i].p2.y);
    }
    compute(lines);
  }
  return 0;
}