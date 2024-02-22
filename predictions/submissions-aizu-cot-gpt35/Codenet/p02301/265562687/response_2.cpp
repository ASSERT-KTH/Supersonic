#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
};

double distance(Point p1, Point p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

double diameter(const vector<Point>& points) {
  double maxDistance = 0.0;
  int n = points.size();
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      double d = distance(points[i], points[j]);
      maxDistance = max(maxDistance, d);
    }
  }
  return maxDistance;
}

int main() {
  int n;
  cin >> n;
  vector<Point> points(n);
  for (int i = 0; i < n; i++)
    cin >> points[i].x >> points[i].y;
  printf("%.12f\n", diameter(points));
  return 0;
}