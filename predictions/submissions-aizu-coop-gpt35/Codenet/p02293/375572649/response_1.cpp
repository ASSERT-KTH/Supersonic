#include <iostream>
#include <cmath>

int main() {
  int n;
  int ax, ay, bx, by, cx, cy, dx, dy;
  std::cin >> n;
  while (n--) {
    std::cin >> ax >> ay >> bx >> by;
    std::cin >> cx >> cy >> dx >> dy;
    int crossProduct = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (std::abs(crossProduct) < 1e-9)
      std::cout << "2\n";
    else if (crossProduct == 0)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}