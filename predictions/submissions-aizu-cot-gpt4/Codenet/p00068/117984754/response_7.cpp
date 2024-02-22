#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <list>
using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::list;
#define EPS (1e-10)

class P {
public:
  double x, y;
  P(double _x = 0, double _y = 0) : x(_x), y(_y) {}
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

double cross(P a, P b) { return a.x * b.y - a.y * b.x; }

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(P *ps, int n) {
  std::sort(ps, ps + n, cmp_x);
  int k = 0;
  list<P> qs;
  for (int i = 0; i < n; ++i) {
    while (k > 1 && cross(*(std::prev(std::prev(qs.end(), 1))) - *(std::prev(qs.end(), 2)), (ps[i] - *(std::prev(qs.end(), 1))) <= 0)) {
      qs.pop_back();
      --k;
    }
    qs.push_back(ps[i]);
    ++k;
  }
  for (int i = n - 2, t = k; i >= 0; --i) {
    while (k > t && cross(*(std::prev(qs.end(), 1)) - *(std::prev(qs.end(), 2)), (ps[i] - *(std::prev(qs.end(), 1))) <= 0)) {
      qs.pop_back();
      --k;
    }
    qs.push_back(ps[i]);
    ++k;
  }
  qs.pop_back();
  return vector<P>(qs.begin(), qs.end());
}

int main() {
  int N;
  while (cin >> N && N) {
    P ps[N];
    for (int i = 0; i < N; ++i) {
      char ch;
      cin >> ps[i].x >> ch >> ps[i].y;
    }
    vector<P> res = convex_hull(ps, N);
    cout << N - res.size() << endl;
  }
}