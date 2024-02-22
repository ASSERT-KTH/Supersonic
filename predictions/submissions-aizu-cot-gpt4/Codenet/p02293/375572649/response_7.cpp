#include <iostream>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double real = (bx - ax) * (dx - cx);
    double imag = (bx - ax) * (cy - dy);
    if (imag == 0)
      cout << "2\n";
    else if (real == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}