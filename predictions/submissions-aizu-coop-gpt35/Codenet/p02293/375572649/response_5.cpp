#include <iostream>

struct Point {
  int x;
  int y;
};

int main() {
  int n;
  int ax, ay, bx, by, cx, cy, dx, dy;
  std::cin >> n;
  while (n--) {
    std::cin >> ax >> ay >> bx >> by;
    std::cin >> cx >> cy >> dx >> dy;
    
    int k = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (k == 0)
      std::cout << "2\n";
    else if ((bx - ax) * (dx - cx) == (by - ay) * (dy - cy))
      std::cout << "1\n";
    else
      std::cout << "0\n";
  }
  return 0;
}