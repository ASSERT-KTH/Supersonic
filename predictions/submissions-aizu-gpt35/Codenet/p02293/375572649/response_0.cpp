#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    double k = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (k == 0)
      printf("2\n");
    else if ((bx - ax) * (dx - cx) + (by - ay) * (dy - cy) == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}