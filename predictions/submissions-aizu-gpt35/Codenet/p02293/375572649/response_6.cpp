#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    double imaginary_part = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (imaginary_part == 0)
      printf("2\n");
    else if ((bx - ax) * (dx - cx) == (by - ay) * (cy - dy))
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}