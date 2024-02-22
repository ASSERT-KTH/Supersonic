#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>
#include <algorithm>
#include <set>

using namespace std;

const string MANY = "Many";
const string NONE = "None";

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

class Line {
public:
  Point p1, p2;
  int index;
  Line(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
};

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

bool intersectSS(Line s, Line t) {
  double c1 = cross(s.p2 - s.p1, t.p1 - s.p1);
  double c2 = cross(s.p2 - s.p1, t.p2 - s.p1);
  double c3 = cross(t.p2 - t.p1, s.p1 - t.p1);
  double c4 = cross(t.p2 - t.p1, s.p2 - t.p1);
  return c1 * c2 < 0 && c3 * c4 < 0;
}

Point crosspoint(Line l, Line m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  assert(fabs(A) > 1e-9);
  return m.p1 + (m.p2 - m.p1) * (B / A);
}

void compute(vector<Line> &vec) {
  if (vec.size() <= 2) {
    cout << MANY << endl;
    return;
  }

  set<Point> candidatePoints;

  for (int i = 0; i < vec.size(); i++) {
    for (int j = i + 1; j < vec.size(); j++) {
      if (intersectSS(vec[i], vec[j])) {
        Point cp = crosspoint(vec[i], vec[j]);
        candidatePoints.insert(cp);
      }
    }
  }

  vector<Point> answer;

  for (auto p : candidatePoints) {
    bool success = true;

    for (int i = 0; i < vec.size(); i++) {
      if (!intersectSS(vec[i], Line(p, p))) {
        success = false;
        break;
      }
    }

    if (success) {
      answer.push_back(p);
      if (answer.size() >= 2) {
        break;
      }
    }
  }

  if (answer.size() == 1)
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  else if (answer.empty())
    cout << NONE << endl;
  else
    cout << MANY << endl;
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<Line> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    }
    compute(vec);
  }
  return 0;
}