#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <cassert>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
#define EPS (1e-10)

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  P operator+(P &p) { return P(x + p.x, y + p.y); }
  P operator-(P &p) { return P(x - p.x, y - p.y); }
  P operator*(double k) { return P(x * k, y * k); }
  P operator/(double k) { return P(x / k, y / k); }
  bool operator==(const P &p) {
    return (fabs(x - p.x) < EPS && fabs(y - p.y) < EPS);
  }
  double norm() { return x * x + y * y; }
  double abs() { return sqrt(norm()); }
};

typedef P Vector;
double dot(Vector &a, Vector &b) { return a.x * b.x + a.y * b.y; }
double cross(Vector &a, Vector &b) { return a.x * b.y - a.y * b.x; }
int ccw(P &p0, P &p1, P &p2) {
  Vector a = p1 - p0;
  Vector b = p2 - p0;
  if (cross(a, b) > EPS)
    return 1;
  if (cross(a, b) < -EPS)
    return -1;
  if (dot(a, b) < -EPS)
    return 2;
  if (a.norm() < b.norm())
    return -2;
  return 0;
}
bool orthogonal(P &p1, P &p2, P &p3, P &p4) {
  return abs(dot(p1 - p2, p3 - p4)) < EPS;
}

// The rest of the code remains unchanged ...