#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;
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
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
int main(void) {
  int n, x, y, v;
  vector<point> P;
  vector<double> V;
  while (cin >> n, n) {
    P.clear();
    V.clear();
    vector<double> distances(n);
    for (int i = 0; i < n; i++) {
      cin >> x >> y >> v;
      P.push_back(point(x, y));
      V.push_back(v);
      distances[i] = dist(point(0, 0), P[i]);
    }
    double r = 0.98;
    point now(0, 0);
    double maxDist = 0;
    for (double d = 10; d > EPS; d *= r) {
      int mx = 0;
      double mxd = 0;
      for (int j = 0; j < P.size(); j++)
        if (distances[j] / V[j] > mxd)
          mx = j, mxd = distances[j] / V[j];
      now = now + ((P[mx] - now) / dist(P[mx], now) * d);
      maxDist = max(maxDist, distances[mx] / V[mx]);
    }
    printf("%.8f\n", maxDist);
  }
  return 0;
}