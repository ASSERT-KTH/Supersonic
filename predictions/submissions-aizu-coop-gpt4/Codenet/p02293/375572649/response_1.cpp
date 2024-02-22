#include <iostream>
#include <complex>

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  std::cin >> n;
  while (n--) {
    std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    const std::complex<double> k = std::complex<double>(bx - ax, by - ay) * std::complex<double>(dx - cx, cy - dy);
    if (k.imag() == 0)
      std::cout << "2\n";
    else if (k.real() == 0)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}