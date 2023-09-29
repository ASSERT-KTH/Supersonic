#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct Point {
  double x, y;
  
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  
  Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double d) const { return Point(x * d, y * d); }
  Point operator/(double d) const { return Point(x / d, y / d); }
};

double dist(const Point& a, const Point& b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main() {
  int n, x, y, v;
  vector<Point> P;
  vector<double> V;
  
  while (cin >> n, n) {
    P.clear();
    V.clear();
    
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.emplace_back(x, y);
      V.push_back(v);
    }
    
    double r = 0.98;
    Point now;
    for (double d = 10; d > 1e-6; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (size_t j = 0; j < P.size(); j++) {
        double currentDistance = dist(now, P[j]) / V[j];
        if (currentDistance > mxd) {
          mx = j;
          mxd = currentDistance;
        }
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    
    double ans = 0;
    for (size_t i = 0; i < P.size(); i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }

  return 0;
}