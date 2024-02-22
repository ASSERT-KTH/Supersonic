#include <iostream>
#include <cmath>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  std::cin >> n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  while (n--) {
    std::cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    double cross_product = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    double dot_product = (bx - ax) * (cx - dx) + (by - ay) * (cy - dy);
    if (std::abs(cross_product) < 1e-9)
      std::cout << "2\n";
    else if (std::abs(dot_product) < 1e-9)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}