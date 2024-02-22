#include <iostream>
#include <complex>
using std::cin;
using std::cout;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double realPart = (bx - ax) * (dx - cx);
    double imagPart = (bx - ax) * (cy - dy);
    if (imagPart == 0)
      cout << "2\n";
    else if (realPart == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}