#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-10;
const double PI = 3.141592653589793238;

struct Point {
  double x, y;
};

double cross(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}

double dist(const Point& a, const Point& b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

double diameter(const vector<Point>& points) {
  int n = points.size();
  if (n < 2) return 0;

  vector<Point> hull;
  sort(points.begin(), points.end(), [](const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
  });

  for (int i = 0; i < n; i++) {
    while (hull.size() >= 2 && cross(
        Point{points[i].x - hull[hull.size() - 2].x, points[i].y - hull[hull.size() - 2].y},
        Point{points[i].x - hull[hull.size() - 1].x, points[i].y - hull[hull.size() - 1].y}) <= 0) {
      hull.pop_back();