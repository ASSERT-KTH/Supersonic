#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

struct P {
  double x, y;
};

double cross(P a, P b) {
  return a.x * b.y - a.y * b.x;
}

bool cmp_x(const P &p, const P &q) {
  if (p.x != q.x)
    return p.x < q.x;
  return p.y < q.y;
}

vector<P> convex_hull(P *ps, size_t n) {
  sort(ps, ps + n, cmp_x);
  size_t k = 0;
  vector<P> qs(n * 2);
  for (size_t i = 0; i < n; i++) {
    while (k > 1 && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  for (size_t i = n - 2, t = k; i > 0; i--) {
    while (k > t && cross((qs[k - 1] - qs[k - 2]), (ps[i] - qs[k - 1])) <= 0)
      k--;
    qs[k++] = ps[i];
  }
  return vector<P>(qs.begin(), qs.begin() + k - 1);
}

int main() {
  int N;
  while (scanf("%d", &N) && N) {
    P ps[100];
    for (int i = 0; i < N; i++) {
      char ch;
      scanf("%lf %c %lf", &ps[i].x, &ch, &ps[i].y);
    }
    vector<P> res = convex_hull(ps, N);
    printf("%d\n", N - static_cast<int>(res.size()));
  }
  return 0;
}