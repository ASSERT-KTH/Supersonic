#include <cstdio>
struct P {
  double x, y;
  P operator-(const P& rhs) const { return {x - rhs.x, y - rhs.y}; }
  P operator*(double rhs) const { return {x * rhs, y * rhs}; }
};
P project(P a, P b, P c) {
  b = b - a, c = c - a;
  double factor = (c.x * b.x + c.y * b.y) / (b.x * b.x + b.y * b.y);
  return {a.x + b.x * factor, a.y + b.y * factor};
}
int main() {
  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);
  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    P p = project({ax, ay}, {bx, by}, {cx, cy});
    printf("%.8f %.8f\n", p.x, p.y);
  }
  return 0;
}