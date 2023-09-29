#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  scanf("%d", &n);
  while (n--) {
    scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by, &dx);
    scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
    P k = P(bx - ax, by - ay) * P(dx - cx, cy - dy);
    if (k.imag() == 0)
      printf("2\n");
    else if (k.real() == 0)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}
