#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

double EPS = 1e-6;

double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b)))
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

double dist(point a, point b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  vector<double> D; // vector for storing distances

  while (cin >> n, n) {
    P.reserve(n); // reserve space to avoid reallocations
    V.reserve(n);
    D.assign(n, 0); // initialize distances to 0

    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
    }

    double r = 0.98;
    point now(0, 0);
    int mx = 0; // keep track of the point with the maximum distance to velocity ratio

    for (double d = 10; d > EPS; d *= r) {
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        D[j] = dist(now, P[j]); // update distance
        double tmp = D[j] / V[j]; // temporary variable for distance to velocity ratio
        if (tmp > mxd) {
          mx = j;
          mxd = tmp;
        }
      }
      now = now + ((P[mx] - now) / D[mx] * d);
    }

    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, D[i] / V[i]); // use stored distance
    }
    printf("%.8f\n", ans);
  }

  return 0;
}