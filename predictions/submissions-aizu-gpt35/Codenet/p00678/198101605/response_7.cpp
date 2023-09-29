#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
const double EPS = 1e-6;
inline double add(double a, double b) {
  return (abs(a + b) < EPS * (abs(a) + abs(b))) ? 0 : a + b;
}
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  inline point operator+(const point &p) const { return point(add(x, p.x), add(y, p.y)); }
  inline point operator-(const point &p) const { return point(add(x, -p.x), add(y, -p.y)); }
  inline point operator*(double d) const { return point(x * d, y * d); }
  inline point operator/(double d) const { return point(x / d, y / d); }
  inline double dist(const point &p) const { return hypot(x - p.x, y - p.y); }
};
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
        if (now.dist(P[j]) / V[j] > mxd)
          mx = j, mxd = now.dist(P[j]) / V[j];
      now = now + ((P[mx] - now) / now.dist(P[mx]) * d);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, now.dist(P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}