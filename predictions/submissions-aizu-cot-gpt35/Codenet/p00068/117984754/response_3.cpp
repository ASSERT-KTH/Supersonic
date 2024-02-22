#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y){};
  P operator+(const P &p) const { return P(x + p.x, y + p.y); }
  P operator-(const P &p) const { return P(x - p.x, y - p.y); }
  P operator*(double k) const { return P(x * k, y * k); }
  P operator/(double k) const { return P(x / k, y / k); }
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
  return distance_l_p(line, center) <= r + EPS;
}

bool isSimple(const Polygon& pol) {
  size_t pol_size = pol.size() - 1;
  for (size_t i = 0; i < pol_size; i++) {
    for (size_t j = i + 2; j < pol_size; j++) {
      if (i == j || i == (j - 1 + pol_size) % pol_size ||
          i == (j + 1 + pol_size) % pol_size)
        continue;
      if (intersect(pol[i], pol[i + 1], pol[j], pol[j + 1]))
        return false;
    }
  }
  return true;
}

bool isPointInsidePolygon(const vector<L>& side, const P& p) {
  int c = count_if(side.begin(), side.end(), [&](const L& s) {
    return cross(s.p2 - s.p1, p - s.p1) > 0;
  });
  return !(c % side.size());
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
  copy_if(ps, ps + n, qs.begin(), [&](const P& p) {
    while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (p - qs[k - 1])) <= 0)
      k--;
    qs[k++] = p;
    return true;
  });
  for (int i = n - 2, t = k; i >= 0; i--) {
    while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  qs.resize(k - 1);
  return qs;
}

#define MAX_N 100

int main() {
  int N;
  P ps[MAX_N];
  while (cin >> N && N) {
    for (int i = 0; i < N; i++) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}