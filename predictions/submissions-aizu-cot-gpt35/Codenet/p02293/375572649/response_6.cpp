#include <iostream>
#include <complex>
using namespace std;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double k_real = (bx - ax) * (dx - cx) + (by - ay) * (dy - cy);
    double k_imag = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (k_imag == 0)
      cout << "2\n";
    else if (k_real == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}