#include <cstdio>
using namespace std;

double project(double ax, double ay, double bx, double by, double cx, double cy) {
  bx -= ax, by -= ay, cx -= ax, cy -= ay;
  double rb = 1.0 / (bx * bx + by * by);
  return ax + bx * (cx * bx + cy * by) * rb;
}

int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    double p = project(ax, ay, bx, by, cx, cy);
    printf("%.8f\n", p);
  }
  return 0;
}