#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Segment {
  Point p1, p2;
  Segment(Point p1, Point p2) : p1(p1), p2(p2) {}
};

const double EPS = 1e-10;

int ccw(Point p, Point q, Point r) {
  double crossProduct = (q.x - p.x) * (r.y - p.y) - (q.y - p.y) * (r.x - p.x);
  if (crossProduct > EPS)
    return 1;
  if (crossProduct < -EPS)
    return -1;
  if ((q.x - p.x) * (r.x - p.x) + (q.y - p.y) * (r.y - p.y) < -EPS)
    return 2;
  if ((q.x - p.x) * (q.x - p.x) + (q.y - p.y) * (q.y - p.y) < (r.x - p.x) * (r.x - p.x) + (r.y - p.y) * (r.y - p.y) - EPS)
    return -2;
  return 0;
}

bool isIntersect(Segment s1, Segment s2) {
  return (ccw(s1.p1, s1.p2, s2.p1) * ccw(s1.p1, s1.p2, s2.p2) <= 0 &&
          ccw(s2.p1, s2.p2, s1.p1) * ccw(s2.p1, s2.p2, s1.p2) <= 0);
}

Point crosspoint(Segment s1, Segment s2) {
  double A1 = s1.p2.x - s1.p1.x;
  double B1 = s1.p2.y - s1.p1.y;
  double A2 = s2.p2.x - s2.p1.x;
  double B2 = s2.p2.y - s2.p1.y;
  double C1 = A1 * s1.p1.x + B1 * s1.p1.y;
  double C2 = A2 * s2.p1.x + B2 * s2.p1.y;
  double det = A1 * B2 - A2 * B1;
  double x = (B2 * C1 - B1 * C2) / det;
  double y = (A1 * C2 - A2 * C1) / det;
  return Point(x, y);
}

int main() {
  int n;
  while (cin >> n && n) {
    int field = 1;
    vector<Segment> segments;
    for (int i = 0; i < n; i++) {
      int x1, y1, x2, y2;
      cin >> x1 >> y1 >> x2 >> y2;
      Segment s(Point(x1, y1), Point(x2, y2));
      segments.push_back(s);
      int xCounter = 0;
      unordered_set<double> exist;
      for (int j = 0; j < i; j++) {
        if (isIntersect(segments[j], segments[i])) {
          Point p = crosspoint(segments[j], segments[i]);
          if (100 - abs(p.x) < EPS || 100 - abs(p.y) < EPS)
            continue;
          double key = p.x * 1000 + p.y;  // Use a unique key for the point
          if (!exist.count(key)) {
            xCounter++;
            exist.insert(key);
          }
        }
      }
      field += xCounter + 1;
    }
    cout << field << endl;
  }
  return 0;
}