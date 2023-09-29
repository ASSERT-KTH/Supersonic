#include <cmath>
#include <cstdio>
#include <vector>

int main() {
  int n;
  std::scanf("%d", &n);
  std::vector<int> ans(n);
  for (int i = 0; i < n; ++i) {
    double xa, ya, ra, xb, yb, rb;
    std::scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double dist = std::hypot(xb - xa, yb - ya);
    double sum = ra + rb;
    double diff1 = std::abs(ra - rb);
    double diff2 = std::abs(rb - ra);
    if (dist > sum) {
      ans[i] = 0;
    } else if (diff1 > dist) {
      ans[i] = 2;
    } else if (diff2 > dist) {
      ans[i] = -2;
    } else {
      ans[i] = 1;
    }
  }
  for (const auto &elem : ans) {
    std::printf("%d\n", elem);
  }
  return 0;
}