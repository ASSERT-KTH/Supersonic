#include <iostream>
#include <complex>

typedef std::complex<double> P;

int main() {
  int n;
  std::cin >> n;

  while (n--) {
    double ax, ay, bx, by, cx, cy, dx, dy;
    std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;

    double k = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);

    if (std::abs(k) < 1e-9) {
      std::cout << "2\n";
    } else if (std::abs(k) < 1e-9) {
      std::cout << "1\n";
    } else {
      std::cout << "0\n";
    }
  }

  return 0;
}