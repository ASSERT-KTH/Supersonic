#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;

P project(P a, P b, P c) {
  c -= a;
  return a + b * real(c / b);
}

int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 
  cout.tie(NULL);

  int n;
  double ax, ay, bx, by, cx, cy;
  scanf("%lf %lf %lf %lf %d", &ax, &ay, &bx, &by, &n);

  P a(ax, ay), b(bx, by);
  b -= a;

  while (n--) {
    scanf("%lf %lf", &cx, &cy);
    P c(cx, cy);
    P p = project(a, b, c);
    printf("%.8f %.8f\n", p.real(), p.imag());
  }

  return 0;
}