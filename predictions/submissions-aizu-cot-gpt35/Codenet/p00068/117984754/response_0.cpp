#include "bits/stdc++.h"
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
struct C {
  P cent;
  double r;
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
bool orthogonal(P p1, P p2, P p3, P p4) {
  return abs(dot(p1 - p2, p3 - p4)) < EPS;
}
bool intersect(P p1, P p2, P p3, P p4) {
  return (ccw(p1, p2, p3) * ccw(p1, p2, p4) <= 0 &&
          ccw(p3, p4, p1) * ccw(p3, p4, p2) <= 0);
}
double distance_l_p(L l, P p) {
  return abs(cross(l.p2 - l.p1, p - l.p1)) / (l.p2 - l.p1).abs();
}
bool intersect_circle_point(P center, double r, L line) {
  if (distance_l_p(line, center) <= r + EPS)
    return true;
  return false;
}
bool isSimple(Polygon pol) {
  size_t pol_size = pol.size() - 1;
  rep(i, pol_size) {
    for (int j = i + 2; j < pol_size; j++) {
      if (i == j || i == (j - 1 + pol_size) % pol_size ||
          i == (j + 1 + pol_size) % pol_size)
        continue;
      if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
        return false;
    }
  }
  return true;
}
bool isPointInsidePolygon(vector<L> side, P p) {
  int c = 0, sideSum = side.size();
  rep(i, sideSum) {
    if (cross(side[i].p2 - side[i].p1, p - side[i].p1) > 0)
      c++;
  }
  return !(c % sideSum);
}
#define MAX_N 100
bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

int N;
P ps[MAX_N];

vector<P> quickHull(vector<P>& points, int left, int right, int side) {
    vector<P> hull;
    int index = -1;
    double dist = side * DBL_MIN;

    for (int i = 0; i < points.size(); i++) {
        double curr_dist = distance_l_p({points[left], points[right]}, points[i]);
        if (ccw(points[left], points[right], points[i]) == side && curr_dist > dist) {
            index = i;
            dist = curr_dist;
        }
    }

    if (index == -1) {
        hull.push_back(points[left]);
        return hull;
    }

    vector<P> left_hull = quickHull(points, left, index, -ccw(points[left], points[index], points[right]));
    vector<P> right_hull = quickHull(points, index, right, -ccw(points[index], points[right], points[left]));

    hull.insert(hull.end(), left_hull.begin(), left_hull.end());
    hull.insert(hull.end(), right_hull.begin(), right_hull.end());

    return hull;
}

vector<P> convex_hull(P *ps, int n) {
  vector<P> points(ps, ps + n);
  sort(points.begin(), points.end(), cmp_x);

  vector<P> upper_hull = quickHull(points, 0, n - 1, 1);
  vector<P> lower_hull = quickHull(points, 0, n - 1, -1);

  upper_hull.insert(upper_hull.end(), lower_hull.begin() + 1, lower_hull.end());

  return upper_hull;
}

int main() {
  while (cin >> N && N) {
    rep(i, N) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}