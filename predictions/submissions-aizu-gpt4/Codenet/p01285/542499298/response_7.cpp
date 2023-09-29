#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cassert>
#define REP(i, s, n) for (int i = s; i < n; i++)
#define rep(i, n) REP(i, 0, n)
#define EPS (1e-6)
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
#define equals(a, b) (fabs((a) - (b)) < EPS)
using namespace std;

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(a * x, a * y); }
  Point operator/(double a) { return Point(x / a, y / a); }
  bool operator<(const Point &p) const {
    return !equals(x, p.x) ? x < p.x : (!equals(y, p.y) && y < p.y);
  }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
  bool operator<(const Segment &s) const {
    return (p2 == s.p2) ? p1 < s.p1 : p2 < s.p2;
  }
  bool operator==(const Segment &s) const {
    return (s.p1 == p1 && s.p2 == p2) || (s.p1 == p2 && s.p2 == p1);
  }
};

typedef Segment Line;
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double norm(Point a) { return a.x * a.x + a.y * a.y; }
double abs(Point a) { return sqrt(norm(a)); }
double toRad(double agl) { return agl * M_PI / 180.0; }

int ccw(Point p0, Point p1, Point p2) {
  Point a = p1 - p0;
  Point b = p2 - p0;
  if (cross(a, b) > EPS)
    return COUNTER_CLOCKWISE;
  if (cross(a, b) < -EPS)
    return CLOCKWISE;
  if (dot(a, b) < -EPS)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

Point crosspoint(Line l, Line m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  if (abs(A) < EPS && abs(B) < EPS) {
    vector<Point> vec;
    vec.push_back(l.p1), vec.push_back(l.p2), vec.push_back(m.p1),
        vec.push_back(m.p2);
    sort(vec.begin(), vec.end());
    assert(vec[1] == vec[2]);
    return vec[1];
  }
  if (abs(A) < EPS)
    assert(false);
  return m.p1 + (m.p2 - m.p1) * (B / A);
}

Line calcLine(Line line1, Line line2, Point p1, Point p2) {
  Point cp = crosspoint(line1, line2);
  int res = ccw(cp, p1, p2);
  Point base;
  if (res == COUNTER_CLOCKWISE)
    base = p1;
  else
    base = p2;
  Point not_base = (base == p1) ? p2 : p1;
  double arg_a = (toRad(180.0) - atan2(base.y - cp.y, base.x - cp.x) +
                  atan2(not_base.y - cp.y, not_base.x - cp.x));
  Point e = (base - cp) / abs(base - cp);
  e = Point(cos(arg_a / 2.0) * e.x - sin(arg_a / 2.0) * e.y,
            sin(arg_a / 2.0) * e.x + cos(arg_a / 2.0) * e.y);
  return Line(cp, cp + e * 100);
}

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << "Many" << endl;
    return;
  }
  vector<Line> candidateLines;
  int n = vec.size();
  rep(i, n) REP(j, i + 1, n) {
    if (equals(cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2), 0.0)) {
      Point e = (vec[i].p2 - vec[i].p1) / abs(vec[i].p2 - vec[i].p1);
      e = Point(-e.y, e.x);
      Point cp1 = vec[i].p1 + e * 100;
      Point cp2 = vec[j].p1 + e * 100;
      Point mp = (cp1 + cp2) / 2.0;
      Line line = Line(mp, mp + (vec[i].p2 - vec[i].p1));
      candidateLines.push_back(line);
    } else {
      Point cp = crosspoint(vec[i], vec[j]);
      Point I = (vec[i].p1 == cp) ? vec[i].p2 : vec[i].p1;
      Point J = (vec[j].p1 == cp) ? vec[j].p2 : vec[j].p1;
      double arg = atan2(I.y - cp.y, I.x - cp.x) -
                   atan2(J.y - cp.y, J.x - cp.x);
      Line tmp = calcLine(vec[i], vec[j], cp + I, cp + J);
      candidateLines.push_back(tmp);
      tmp = calcLine(vec[i], vec[j], cp + I, cp - J);
      candidateLines.push_back(tmp);
    }
    if (candidateLines.size() >= 10)
      break;
  }
  vector<Point> candidatePoints;
  rep(i, candidateLines.size()) REP(j, i + 1, candidateLines.size()) {
    Line line1 = candidateLines[i];
    Line line2 = candidateLines[j];
    if (equals(cross(line1.p1 - line1.p2, line2.p1 - line2.p2), 0.0))
      continue;
    Point cp = crosspoint(line1, line2);
    candidatePoints.push_back(cp);
  }
  sort(candidatePoints.begin(), candidatePoints.end());
  candidatePoints.erase(
      unique(candidatePoints.begin(), candidatePoints.end()),
      candidatePoints.end());
  vector<Point> answer;
  rep(i, candidatePoints.size()) {
    Point p = candidatePoints[i];
    double dist = -1;
    bool success = true;
    rep(j, vec.size()) {
      double tmp = abs(p - crosspoint(vec[j], Line(p, p + Point(1, 0))));
      if (equals(dist, -1))
        dist = tmp;
      else if (!equals(dist, tmp)) {
        success = false;
        break;
      }
    }
    if (success)
      answer.push_back(p);
    if (answer.size() >= 2)
      break;
  }
  if (answer.size() == 1)
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  else if (answer.empty())
    cout << "None" << endl;
  else
    cout << "Many" << endl;
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<Line> vec(n);
    rep(i, n) cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    compute(vec);
  }
  return 0;
}