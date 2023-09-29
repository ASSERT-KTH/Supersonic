#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

double EPS = 1e-6;

inline double add(double a, double b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b)))
    return 0;
  return a + b;
}

struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  inline point operator+(const point& p) const { return point(add(x, p.x), add(y, p.y)); }
  inline point operator-(const point& p) const { return point(add(x, -p.x), add(y, -p.y)); }
  inline point operator*(double d) const { return point(x * d, y * d); }
  inline point operator/(double d) const { return point(x / d, y / d); }
};

inline double dist(const point& a, const point& b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  while (cin >> n, n) {
    vector<point> P(n);
    vector<double> V(n);

    for (int i = 0; i < n; i++) {
      int x, y, v;
      cin >> x >> y >> v;
      P[i] = point(x, y);
      V[i] = v;
    }

    double r = 0.98;
    point now(0, 0);

    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        double cur = dist(now, P[j]) / V[j];
        if (cur > mxd) {
          mx = j;
          mxd = cur;
        }
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