#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Point {
public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};

struct Segment {
  Point p1, p2;
  int index;
  Segment(Point p1 = Point(), Point p2 = Point(), int index = -1)
      : p1(p1), p2(p2), index(index) {}
};

typedef vector<Point> Polygon;

double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }

Point crosspoint(Segment l, Segment m) {
  double A = cross(l.p2 - l.p1, m.p2 - m.p1);
  double B = cross(l.p2 - l.p1, l.p2 - m.p1);
  return m.p1 + (m.p2 - m.p1) * (B / A);
}

bool intersectSS(Segment s, Segment t) {
  return cross(s.p1, s.p2, t.p1) * cross(s.p1, s.p2, t.p2) <= 0 &&
         cross(t.p1, t.p2, s.p1) * cross(t.p1, t.p2, s.p2) <= 0;
}

const string MANY = "Many";
const string NONE = "None";

void compute(vector<Segment>& vec) {
  if (vec.size() <= 2) {
    cout << MANY << endl;
    return;
  }
  
  vector<Segment> candidateLines;
  int n = vec.size();
  
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      Point cp = crosspoint(vec[i], vec[j]);
      Segment tmp = { cp, cp + Point(1, 0) };
      int Index = candidateLines.size();
      tmp.index = Index;
      candidateLines.push_back(tmp);
    }
  }
  
  vector<Point> candidatePoints;
  
  for (int i = 0; i < candidateLines.size(); i++) {
    for (int j = i + 1; j < candidateLines.size(); j++) {
      Segment line1 = candidateLines[i];
      Segment line2 = candidateLines[j];
      if (intersectSS(line1, line2)) {
        Point cp = crosspoint(line1, line2);
        candidatePoints.push_back(cp);
      }
    }
  }
  
  sort(candidatePoints.begin(), candidatePoints.end());
  candidatePoints.erase(unique(candidatePoints.begin(), candidatePoints.end()), candidatePoints.end());
  
  vector<Point> answer;
  
  for (int i = 0; i < candidatePoints.size(); i++) {
    Point p = candidatePoints[i];
    double dist = -1;
    bool success = true;
    for (int j = 0; j < vec.size(); j++) {
      double tmp = distanceLP(vec[j], p);
      if (dist == -1) {
        dist = tmp;
      } else if (dist != tmp) {
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
  
  if (answer.size() == 1) {
    printf("%.10f %.10f\n", answer[0].x, answer[0].y);
  } else if (answer.empty()) {
    cout << NONE << endl;
  } else {
    cout << MANY << endl;
  }
}

int main() {
  int n;
  while (cin >> n, n) {
    vector<Segment> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i].p1.x >> vec[i].p1.y >> vec[i].p2.x >> vec[i].p2.y;
    }
    compute(vec);
  }
  return 0;
}