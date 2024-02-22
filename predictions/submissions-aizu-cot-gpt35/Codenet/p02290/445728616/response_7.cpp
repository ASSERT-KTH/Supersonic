#include <iostream>
#include <complex>
using std::cin;
using std::cout;
using std::endl;
using std::complex;

complex<double> project(const complex<double>& a, const complex<double>& b, const complex<double>& c) {
  complex<double> diff_b = b - a;
  complex<double> diff_c = c - a;
  return a + diff_b * real(diff_c / diff_b);
}

int main() {
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by;
  
  int n;
  cin >> n;
  
  complex<double> a(ax, ay);
  complex<double> b(bx, by);
  
  complex<double> diff_b = b - a;
  
  while (n--) {
    cin >> cx >> cy;
    complex<double> c(cx, cy);
    complex<double> p = project(a, b, c);
    cout << std::fixed << std::setprecision(8) << p.real() << " " << p.imag() << endl;
  }
  
  return 0;
}