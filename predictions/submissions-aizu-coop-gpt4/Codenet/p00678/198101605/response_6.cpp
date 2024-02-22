#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;

struct point {
  double x, y, v;
  point() {}
  point(double x, double y, double v) : x(x), y(y), v(v) {}
  point operator+(point p) { return point(x + p.x, y + p.y, v); }
  point operator-(point p) { return point(x - p.x, y - p.y, v); }
  point operator*(double d) { return point(x * d, y * d, v); }
  point operator/(double d) { return point(x / d, y / d, v); }
};

double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  int n;
  double x, y, v;
  vector<point> P;
  while (cin >> n, n) {
    P.clear();
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y, v));
    }
    double r = 0.98;
    point now(0, 0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < P.size(); j++) {
        double currentDist = dist(now, P[j]) / P[j].v;
        if (currentDist > mxd)
          mx = j, mxd = currentDist;
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    double ans = 0;
    for (int i = 0; i < P.size(); i++) {
      ans = max(ans, dist(now, P[i]) / P[i].v);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}