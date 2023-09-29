#include <cmath>
#include <cstdio>
#include <vector>

int main(void) {
  int n;
  scanf("%d", &n);
  std::vector<int> ans(n);
  double xa, ya, ra, xb, yb, rb;
  for (int k = 0; k < n; k++) {
    scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
    double d = std::hypot(xb - xa, yb - ya);
    double ra_plus_rb = ra + rb;
    double ra_minus_rb = std::abs(ra - rb);
    if (d > ra_plus_rb) {
      ans[k] = 0;
    } else if (ra_minus_rb > d) {
      ans[k] = (ra > rb) ? 2 : -2;
    } else {
      ans[k] = 1;
    }
  }
  for (int ans_val : ans) {
    printf("%d\n", ans_val);
  }
  return 0;
}