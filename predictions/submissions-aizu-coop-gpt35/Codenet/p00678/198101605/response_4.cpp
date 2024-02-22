#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

double EPS = 1e-6;

double add(double a, double b) {
  if (abs(a + b) < EPS)
    return 0;
  return a + b;
}

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(point p) { return point(add(x, p.x), add(y, p.y)); }
  point operator-(point p) { return point(add(x, -p.x), add(y, -p.y)); }
  point operator*(double d) { return point(x * d, y * d); }
  point operator/(double d) { return point(x / d, y / d); }
};

double distSquared(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;

  // Reserve memory for maximum possible number of points and velocities
  P.reserve(10000);
  V.reserve(10000);

  while (true) {
    cin >> n;
    if (n == 0) break;

    P.resize(n);
    V.resize(n);

    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P[i] = point(x, y);
      V[i] = v;
    }

    double r = 0.98;
    point now(0, 0);

    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxdSquared = 0;

      for (int j = 0; j < n; j++) {
        double distSq = distSquared(now, P[j]);
        if (distSq > mxdSquared) {
          mx = j;
          mxdSquared = distSq;
        }
      }

      now = now + ((P[mx] - now) * d);
    }

    double ansSquared = 0;

    for (int i = 0; i < n; i++) {
      double distSq = distSquared(now, P[i]);
      ansSquared = max(ansSquared, distSq / (V[i] * V[i]));
    }

    double ans = sqrt(ansSquared);
    printf("%.8f\n", ans);
  }

  return 0;
}