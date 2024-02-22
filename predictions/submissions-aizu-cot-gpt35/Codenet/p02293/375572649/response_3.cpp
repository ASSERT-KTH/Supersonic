#include <iostream>
using namespace std;

struct Point {
  double x, y;
};

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double k_real = (bx - ax) * (dx - cx) + (by - ay) * (dy - cy);
    double k_imag = (bx - ax) * (cy - dy) - (by - ay) * (cx - dx);
    if (k_imag == 0)
      cout << "2" << endl;
    else if (k_real == 0)
      cout << "1" << endl;
    else
      cout << "0" << endl;
  }
  return 0;
}