#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using ll = long long;
using pii = std::pair<int, int>;
constexpr double EPS = 1e-10;
constexpr int MAX_N = 100;

struct P {
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

using Vector = P;
using Polygon = std::vector<P>;

double dot(Vector a, Vector b) { return a.x * b.x + a.y * b.y; }
double cross(Vector a, Vector b) { return a.x * b.y - a.y * b.x; }

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

std::vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  std::vector<P> qs(n * 2);
  for (ll i = 0; i < (ll)(n); i++) {
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

int main() {
  int N;
  P ps[MAX_N];
  while (std::cin >> N && N) {
    for (ll i = 0; i < (ll)(N); i++) {
      std::cin >> ps[i].x >> ps[i].y;
    }
    std::vector<P> res = convex_hull(ps, N);
    std::cout << N - res.size() << std::endl;
  }
}