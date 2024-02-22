#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

#define EPS 1e-10
#define F first
#define S second
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0

using namespace std;

struct Point {
  double x, y;

  Point(double x = 0, double y = 0) : x(x), y(y) {}

  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(const Point& p) const { return Point(x * p.x, y * p.y); }
  Point operator/(const Point& p) const { return Point(x / p.x, y / p.y); }

  bool operator==(const Point& p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }

  bool operator<(const Point& p) const {
    return x != p.x ? fabs(x - p.x) < EPS : fabs(y - p.y) < EPS;
  }
};

typedef pair<Point, Point> Segment;

double dot(const Point& a, const Point& b) { return a.x * b.x + a.y * b.y; }

double cross(const Point& a, const Point& b) { return a.x * b.y - a.y * b.x; }

double norm(const Point& p) { return p.x * p.x + p.y * p.y; }

int ccw(const Point& p, const Point& q, const Point& r) {
  Point a = q - p;
  Point b = r - p;
  double crossProduct = cross(a, b);
  if (crossProduct > EPS)
    return COUNTER_CLOCKWISE;
  if (crossProduct < -EPS)
    return CLOCKWISE;
  if (dot(a, b) < -EPS)
    return ONLINE_BACK;
  if (norm(a) < norm(b))
    return ONLINE_FRONT;
  return ON_SEGMENT;
}

bool isIntersect(const Point& p1, const Point& p2, const Point& p3,
                 const Point& p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

Point crosspoint(const Point& p1, const Point& p2, const Point& p3,
                 const Point& p4) {
  double crossProduct = cross(p2 - p1, p4 - p3);
  double B = cross(p2 - p1, p2 - p3);
  Point pro = p4 - p3;
  pro.x = pro.x * (B / crossProduct);
  pro.y = pro.y * (B / crossProduct);
  return p3 + pro;
}

int main() {
  int n, x1, y1, x2, y2, field;
  vector<Segment> segments;
  set<Point> intersectionPoints;
  Point intersectionPoint;

  while (cin >> n && n) {
    field = 1;
    segments.clear();
    for (int i = 0; i < n; i++) {
      cin >> x1 >> y1 >> x2 >> y2;
      Segment segment(Point(x1, y1), Point(x2, y2));
      segments.push_back(segment);
      int intersectionCount = 0;
      bool isNewIntersection = true;
      intersectionPoints.clear();
      for (int j = 0; j < segments.size() - 1; j++) {
        isNewIntersection = true;
        if (isIntersect(segments[j].F, segments[j].S, segments.back().F,
                        segments.back().S)) {
          intersectionPoint = crosspoint(segments[j].F, segments[j].S,
                                         segments.back().F, segments.back().S);
          if (100 - fabs(intersectionPoint.x) < EPS ||
              100 - fabs(intersectionPoint.y) < EPS)
            continue;
          if (intersectionPoints.count(intersectionPoint)) {
            isNewIntersection = false;
          }
          if (isNewIntersection) {
            intersectionCount++;
            intersectionPoints.insert(intersectionPoint);
          }
        }
        if (!isNewIntersection) {
          break;  // No need to check further intersections
        }
      }
      field += intersectionCount + 1;
    }
    cout << field << endl;
  }
  return 0;
}