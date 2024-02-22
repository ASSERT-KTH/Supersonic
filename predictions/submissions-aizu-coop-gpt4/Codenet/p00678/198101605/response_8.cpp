#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1e-6;

double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b)))
    return 0;
  return a + b;
}

struct point {
  double x, y;
  double v; // add speed as part of the point structure
  point() {}
  point(double x, double y, double v) : x(x), y(y), v(v) {}
  point operator+(point p) { return point(add(x, p.x), add(y, p.y)); }
  point operator-(point p) { return point(add(x, -p.x), add(y, -p.y)); }
  point operator*(double d) { return point(x * d, y * d); }
  point operator/(double d) { return point(x / d, y / d); }
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
    point now(0, 0);

    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      double temp_dist;
      for (int j = 0; j < P.size(); j++) {
        temp_dist = dist(now, P[j]); // calculate distance only once
        if (temp_dist / P[j].v > mxd)
          mx = j, mxd = temp_dist / P[j].v;
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