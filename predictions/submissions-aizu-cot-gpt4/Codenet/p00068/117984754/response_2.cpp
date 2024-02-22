#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <array>

using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
#define EPS (1e-10)

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  const P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  const P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  const P operator*(double k) const { return P(x * k, y * k); }
  const P operator/(double k) const { return P(x / k, y / k); }
  bool operator==(const P &p) const {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
  double norm() const { return x * x + y * y; }
  double abs() const { return sqrt(norm()); }
};
struct C {
  P cent;
  double r;
};
struct L {
  P p1, p2;
};
using Polygon = vector<P>;
using Vector = P;

static double dot(const Vector &a, const Vector &b) { return a.x * b.x + a.y * b.y; }
static double cross(const Vector &a, const Vector &b) { return a.x * b.y - a.y * b.x; }
static int ccw(const P &p0, const P &p1, const P &p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS)
    return 1;
  if (cross(a, b) < -EPS)
    return -1;
  ...

// rest of the code remains the same