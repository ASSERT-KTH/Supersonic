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

double dist(point a, point b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
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
      double mxd = 0;
      for (int j = 0; j < n; j++)
        if (dist(now, P[j]) / V[j] > mxd)
          mx = j, mxd = dist(now, P[j]) / V[j];
      now = now + ((P[mx] - now) / sqrt(dist(P[mx], now)) * d);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", sqrt(ans));
  }
  return 0;
}