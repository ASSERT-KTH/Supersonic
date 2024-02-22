#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

const double EPS = 1e-10;
const double PI = 3.141592653589793238;
typedef long long ll;

struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  Point operator+(const Point &p) const { return Point(x + p.x, y + p.y); }
  Point operator-(const Point &p) const { return Point(x - p.x, y - p.y); }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
};

typedef Point Vector;
typedef vector<Point> Polygon;

double norm(const Vector &a) { return a.x * a.x + a.y * a.y; }
double abs(const Vector &a) { return sqrt(norm(a)); }
double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }

Polygon convex_hull(Polygon& ps) {
  int n = ps.size();
  sort(ps.begin(), ps.end());
  int k = 0;
  Polygon qs(n * 2);
  for (int i = 0; i < n; i++) {
    while (k > 1 && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross(qs[k - 1] - qs[k - 2], ps[i] - qs[k - 1]) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

double diameter(const Polygon& s) {
  Polygon p = convex_hull(const_cast<Polygon&>(s));
  int n = p.size();
  if (n == 2)
    return abs(p[0] - p[1]);
  int i = 0, j = 0;
  for (int k = 0; k < n; k++) {
    if (p[i] < p[k])
      i = k;
    if (!(p[j] < p[k]))
      j = k;
  }
  double res = 0;
  int si = i, sj = j;
  while (i != sj || j != si) {
    res = max(res, abs(p[i] - p[j]));
    if (cross(p[(i + 1) % n] - p[i], p[(j + 1) % n] - p[j]) < 0.0) {
      i = (i + 1) % n;
    } else {
      j = (j + 1) % n;
    }
  }
  return res;
}

int main() {
  int n;
  cin >> n;
  Polygon p(n);
  for (int i = 0; i < n; i++)
    cin >> p[i].x >> p[i].y;
  cout << fixed << setprecision(12) << diameter(p) << endl;
  return 0;
}