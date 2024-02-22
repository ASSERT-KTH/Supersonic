#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y) {};
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

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n) {
  sort(ps, ps + n, cmp_x);
  int k = 0;
  vector<P> qs(n * 2);
  for (int i = 0; i < n; i++) {
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
  while (cin >> N && N) {
    vector<P> ps(N);
    for (int i = 0; i < N; i++) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps.data(), N);
    cout << N - res.size() << endl;
  }
}