#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
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
  point P[1000];  // static array to hold points
  double V[1000]; // static array to hold velocities
  double D[1000]; // static array to hold distances
  double T[1000]; // static array to hold times
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P[i] = point(x, y);
      V[i] = v;
      D[i] = dist(point(0, 0), P[i]);
      T[i] = D[i] / V[i];
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++)
        if (T[j] > mxd)
          mx = j, mxd = T[j];
      now = now + ((P[mx] - now) / D[mx] * d);
      D[mx] = dist(now, P[mx]);
      T[mx] = D[mx] / V[mx];
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, T[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}