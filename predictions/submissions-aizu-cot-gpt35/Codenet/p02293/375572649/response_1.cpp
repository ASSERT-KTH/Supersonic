#include <iostream>
#include <complex>
using namespace std;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    complex<double> k = complex<double>(bx - ax, by - ay) * complex<double>(dx - cx, cy - dy);
    if (k.imag() == 0)
      cout << "2\n";
    else if (k.real() == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}