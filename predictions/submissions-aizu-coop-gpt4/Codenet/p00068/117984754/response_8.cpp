#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define all(a) (a).begin(), (a).end()
#define vi vector<int>
#define pb push_back
#define INF 999999999
constexpr double EPS = 1e-10;
constexpr int MAX_N = 100;

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

struct L {
  P p1, p2;
};

typedef vector<P> Polygon;
typedef P Vector;
double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }
int ccw(P p0, P p1, P p2) {
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

bool intersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}

double distance_l_p(L l, P p) {
  return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}

bool intersect_circle_point(P center, double r, L line) {
  double distance = cross(line.p2 - line.p1, center - line.p1);
  return (distance * distance <= r * r * (line.p2 - line.p1).norm() + EPS);
}

bool isPointInsidePolygon(vector<L> side, P p) {
  int c = 0, sideSum = side.size();
  rep(i, sideSum) {
    if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
      c++;
  }
  return !(c % sideSum);
}

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  rep(i, n) {
    while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

int N;
P ps[MAX_N];
int main() {
  while (cin >> N && N) {
    rep(i, N) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    auto res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}