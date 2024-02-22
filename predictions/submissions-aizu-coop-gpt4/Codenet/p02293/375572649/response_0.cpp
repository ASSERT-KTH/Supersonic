#include <iostream>
using namespace std;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double cross_product = (bx - ax) * (dy - cy) - (by - ay) * (dx - cx);
    if (cross_product == 0)
      cout << "2\n";
    else if (cross_product > 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}