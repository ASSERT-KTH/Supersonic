#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;

double add(double a, double b) {
  double sum = a + b;
  if (fabs(sum) < EPS * (fabs(a) + fabs(b))) {
    return 0;
  }
  return sum;
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
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}

int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
    P.clear();
    V.clear();
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      double maxDist = 0;
      int maxIndex = 0;
      for (int j = 0; j < P.size(); j++) {
        double distance = dist(now, P[j]) / V[j];
        if (distance > maxDist) {
          maxDist = distance;
          maxIndex = j;
        }
      }
      now = now + ((P[maxIndex] - now) / dist(P[maxIndex], now) * d);
    }
    double ans = 0;
    for (int i = 0; i < P.size(); i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}