#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <array>
using namespace std;
double EPS = 1e-6;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(point p) { 
    if (abs(x + p.x) < EPS * (abs(x) + abs(p.x))) x = 0; 
    else x += p.x;
    if (abs(y + p.y) < EPS * (abs(y) + abs(p.y))) y = 0; 
    else y += p.y;
    return *this;
  }
  point operator-(point p) { 
    if (abs(x - p.x) < EPS * (abs(x) + abs(p.x))) x = 0; 
    else x -= p.x;
    if (abs(y - p.y) < EPS * (abs(y) + abs(p.y))) y = 0; 
    else y -= p.y;
    return *this;
  }
  point operator*(double d) { return point(x * d, y * d); }
  point operator/(double d) { return point(x / d, y / d); }
};
double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main(void) {
  int n, x, y, v;
  array<point, 100> P; // Arbitrarily chosen size, adjust as per your requirement
  array<double, 100> V; // Arbitrarily chosen size, adjust as per your requirement
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P[i] = point(x, y);
      V[i] = v;
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++){
        double current_distance = dist(now, P[j]) / V[j];
        if (current_distance > mxd)
          mx = j, mxd = current_distance;
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}