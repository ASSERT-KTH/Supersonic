#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
double EPS = 1e-6;

double add(double a, double b) {
  double abs_a = abs(a);
  double abs_b = abs(b);
  if (abs(a + b) < EPS * (abs_a + abs_b))
    return 0;
  return a + b;
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
      
      for (int j = 0; j < n; j++) {
        double cur_dist = dist(now, P[j]) / V[j];
        if (cur_dist > mxd) {
          mx = j;
          mxd = cur_dist;
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