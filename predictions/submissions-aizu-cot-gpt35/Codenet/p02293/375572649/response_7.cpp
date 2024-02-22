#include <iostream>
#include <complex>
using namespace std;

typedef complex<double> P;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;

  cin >> n;

  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;

    P k = P(bx - ax, by - ay) * P(dx - cx, cy - dy);

    if (k.imag() == 0)
      cout << "2\n";
    else if (k.real() == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }

  return 0;
}