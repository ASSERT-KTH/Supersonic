#include <iostream>

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  std::cin >> n;
  while (n--) {
    std::cin >> ax >> ay >> bx >> by;
    std::cin >> cx >> cy >> dx >> dy;
    double k = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (k == 0)
      std::cout << "2\n";
    else if (k > 0)
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}