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
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(point p) { return point(x + p.x, y + p.y); }
  point operator-(point p) { return point(x - p.x, y - p.y); }
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
  while (cin >> n, n) {
    P.clear();
    V.clear();
    P.reserve(n);
    V.reserve(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      double tmp_d;
      int P_size = P.size();
      for (int j = 0; j < P_size; j++) {
        tmp_d = dist(now, P[j]) / V[j];
        if (tmp_d > mxd)
          mx = j, mxd = tmp_d;
      }
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
    }
    double ans = 0;
    int P_size = P.size();
    for (int i = 0; i < P_size; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}