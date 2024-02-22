#include <iostream>
#include <complex>

using namespace std;
typedef complex<double> P;

P project(P& a, P& b, P& c) {
  b -= a; 
  c -= a;
  return a + b * real(c / b);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> n;

  P a(ax, ay), b(bx, by), c;

  while (n--) {
    cin >> cx >> cy;
    c.real(cx); 
    c.imag(cy);
    
    P p = project(a, b, c);
    cout << setprecision(8) << p.real() << " " << p.imag() << "\n";
  }

  return 0;
}