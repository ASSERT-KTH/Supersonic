#include <algorithm>
#include <cmath>
#include <cstdio>
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
double dist(const point& a, const point& b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx * dx + dy * dy);
}
int main() {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (scanf("%d", &n), n) {
    P.clear();
    V.clear();
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d", &x, &y, &v);
      P.emplace_back(x, y);
      V.push_back(v);
    }
    const double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < P.size(); j++) {
        double curr_dist = dist(now, P[j]);
        if (curr_dist / V[j] > mxd)
          mx = j, mxd = curr_dist / V[j];
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