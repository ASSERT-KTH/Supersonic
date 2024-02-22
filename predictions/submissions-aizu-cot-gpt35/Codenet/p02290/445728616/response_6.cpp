#include <iostream>
#include <complex>
using namespace std;

using P = complex<double>;

P project(const P& a, const P& b, const P& c) {
  P diff_b = b - a;
  P diff_c = c - a;
  return a + diff_b * real(diff_c / diff_b);
}

int main() {
  double ax, ay, bx, by, cx, cy;
  int n;
  cin >> ax >> ay >> bx >> by >> n;
  
  P point_a(ax, ay);
  P point_b(bx, by);
  
  while (n--) {
    cin >> cx >> cy;
    P point_c(cx, cy);
    P p = project(point_a, point_b, point_c);
    cout << fixed << setprecision(8) << p.real() << " " << p.imag() << endl;
  }
  
  return 0;
}