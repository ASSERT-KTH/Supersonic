#include <iostream>
#include <complex>

using namespace std;
typedef complex<double> P;

P project(P &a, P &b, P &c) {
  b -= a; 
  c -= a;
  return a + b * real(c / b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;
  
  P a(ax, ay), b(bx, by);
  
  while (--n >= 0) {
    cin >> cx >> cy;
    P c(cx, cy);
    P p = project(a, b, c);
    printf("%.8f %.8f\n", p.real(), p.imag());
  }
  
  return 0;
}