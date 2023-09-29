#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

const double EPS = 1e-6;

inline double add(const double &a, const double &b) {
  if (abs(a + b) < EPS * (abs(a) + abs(b)))
    return 0;
  return a + b;
}

struct point {
  double x, y;
  point() {}
  point(const double &x, const double &y) : x(x), y(y) {}
  point operator+(const point &p) { 
    return point(add(x, p.x), add(y, p.y)); 
  }
  point operator-(const point &p) { 
    return point(add(x, -p.x), add(y, -p.y)); 
  }
  point operator*(const double &d) { 
    return point(x * d, y * d); 
  }
  point operator/(const double &d) { 
    return point(x / d, y / d); 
  }
};

inline double dist(const point &a, const point &b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (scanf("%d", &n), n) {
    P.clear();
    V.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d", &x, &y, &v);
      P.emplace_back(x, y);
      V.emplace_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++)
        if (dist(now, P[j]) / V[j] > mxd)
          mx = j, mxd = dist(now, P[j]) / V[j];
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