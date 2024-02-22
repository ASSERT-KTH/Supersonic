#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

#define EPS (1e-6)
#define equals(a, b) (fabs((a) - (b)) < EPS)

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  // ...
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
  // ...
};

typedef Point Vector;
typedef Segment Line;

double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double norm(Point a) { return a.x * a.x + a.y * a.y; }
double abs(Point a) { return sqrt(norm(a)); }
Point rotate(Point a, double rad) {
  return Point(cos(rad) * a.x - sin(rad) * a.y,
               sin(rad) * a.x + cos(rad) * a.y);
}
double toRad(double agl) { return agl * M_PI / 180.0; }
bool equals(const Point &a, const Point &b) {
  return fabs(a.x - b.x) < EPS && fabs(a.y - b.y) < EPS;
}

// ... other functions

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << "Many" << endl;
    return;
  }
  
  vector<Line> candidateLines;
  int n = vec.size();
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (equals(cross(vec[i].p1 - vec[i].p2, vec[j].p1 - vec[j].p2), 0.0)) {
        Vector e = (vec[i].p2 - vec[i].p1) / abs(vec[i].p2 - vec[i].p1);
        e = rotate(e, toRad(90));
        Line line = Line(vec[i].p1, vec[i].p1 + e * 100);
        Point cp1 = crosspoint(line, vec[i]);
        Point cp2 = crosspoint(line, vec[j]);
        Point mp = (cp1 + cp2) / 2.0;
        e = (vec[i].p2 - vec[i].p1) / abs(vec[i].p2 - vec[i].p1);
        line = Line(mp, mp + e * 100);
        line.index = candidateLines.size();
        candidateLines.push_back(line);
      } else {
        Point cp = crosspoint(vec[i], vec[j]);
        Point I = (vec[i].p1 == cp) ? vec[i].p2 : vec[i].p1;