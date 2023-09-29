#include <cstdio>
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
    P k = P(bx - ax, by - ay) * P(dx - cx, cy - dy);
    if (abs(k.imag()) < 1e-10)
      printf("2\n");
    else if (abs(k.real()) < 1e-10)
      printf("1\n");
    else
      printf("0\n");
  }
  return 0;
}