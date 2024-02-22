#include <algorithm>
#include <cmath>
#include <cstdio>
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
  point operator+(const point &p) const { return point(add(x, p.x), add(y, p.y)); }
  point operator-(const point &p) const { return point(add(x, -p.x), add(y, -p.y)); }
  point operator*(double d) const { return point(x * d, y * d); }
  point operator/(double d) const { return point(x / d, y / d); }
};
double dist(const point &a, const point &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}
int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (scanf("%d", &n), n) {
    P.resize(n);
    V.resize(n);
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &x, &y, &v);
      P[i] = point(x, y);
      V[i] = v;
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0, mxdist;
      for (int j = 0; j < P.size(); j++) {
        mxdist = dist(now, P[j]) / V[j];
        if (mxdist > mxd)
          mx = j, mxd = mxdist;
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    double ans = 0;
    for (int i = 0; i < P.size(); i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}