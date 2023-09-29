#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;
const double EPS = 1e-6;
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
  return sqrt(dx * dx + dy * dy);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
    P.resize(n);
    V.resize(n);
    for (int i = 0; i < n; i++) {
      cin >> P[i].x >> P[i].y >> V[i];
    }
    double r = 0.98;
    point now(0, 0);
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < n; j++) {
        double curDist = dist(now, P[j]);
        if (curDist / V[j] > mxd)
          mx = j, mxd = curDist / V[j];
      }
      now = now + ((P[mx] - now) / dist(now, P[mx]) * d);
    }
    double ans = 0;
    for (int i = 0; i < n; i++) {
      ans = max(ans, dist(now, P[i]) / V[i]);
    }
    printf("%.8f\n", ans);
  }
  return 0;
}