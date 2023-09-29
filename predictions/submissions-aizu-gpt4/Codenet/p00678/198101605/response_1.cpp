#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
constexpr double EPS = 1e-6;
struct point {
  double x, y;
  point() {}
  point(double x, double y) : x(x), y(y) {}
  point operator+(const point& p) const { return point(x + p.x, y + p.y); }
  point operator-(const point& p) const { return point(x - p.x, y - p.y); }
  point operator*(double d) const { return point(x * d, y * d); }
  point operator/(double d) const { return point(x / d, y / d); }
};
inline double dist(const point& a, const point& b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}
int main(void) {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
      P.emplace_back(x, y);
      V.push_back(v);
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        double tempDist = dist(now, P[j]);
        double tempVal = tempDist / V[j];
        if (tempVal > mxd)
          mx = j, mxd = tempVal;
      }
      point dir = (P[mx] - now);
      now = now + dir / dist(now, P[mx]) * d;
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}