#include <iostream>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    // calculate the cross product
    double real = (bx - ax)*(dy - cy) - (by - ay)*(dx - cx);
    if (real == 0)
      cout << "2\n";
    else if ((dy - cy)*(bx - ax) - (dx - cx)*(by - ay) == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}