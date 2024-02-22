#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#define EPS (1e-9)
#define equals(a, b) (fabs((a) - (b)) < EPS)
#define PI 3.141592653589793238
#define int long long
#define COUNTER_CLOCKWISE 1
#define CLOCKWISE -1
#define ONLINE_BACK 2
#define ONLINE_FRONT -2
#define ON_SEGMENT 0
using namespace std;

struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) const { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) const { return Point(x - p.x, y - p.y); }
  Point operator*(double k) const { return Point(x * k, y * k); }
  Point operator/(double k) const { return Point(x / k, y / k); }
  double norm() const { return x * x + y * y; }
  double abs() const { return sqrt(norm()); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < EPS && fabs(y - p.y) < EPS;
  }
};

// Rest of the code remains same...

signed main() {
  int n;
  cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i];
  printf("%.12f\n", diameter(p));
  return 0;
}