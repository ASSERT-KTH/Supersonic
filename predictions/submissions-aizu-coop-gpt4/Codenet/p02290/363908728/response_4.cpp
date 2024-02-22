#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
};

struct Line {
  Point p1, p2;
};

double dot(const Point &a, const Point &b) {
  return a.x * b.x + a.y * b.y;
}

Point projection(const Line &L, const Point &p) {
  double t = dot({p.x - L.p1.x, p.y - L.p1.y}, {L.p2.x - L.p1.x, L.p2.y - L.p1.y}) / 
              (pow(L.p2.x - L.p1.x, 2) + pow(L.p2.y - L.p1.y, 2));
  return {L.p1.x + t * (L.p2.x - L.p1.x), L.p1.y + t * (L.p2.y - L.p1.y)};
}

int main() {
  Line L;
  cin >> L.p1.x >> L.p1.y >> L.p2.x >> L.p2.y;
  int Q;
  cin >> Q;
  vector<Point> points(Q);
  for (int i = 0; i < Q; i++) {
    cin >> points[i].x >> points[i].y;
  }
  for (int i = 0; i < Q; i++) {
    Point w = projection(L, points[i]);
    cout << w.x << " " << w.y << endl;
  }
  return 0;
}