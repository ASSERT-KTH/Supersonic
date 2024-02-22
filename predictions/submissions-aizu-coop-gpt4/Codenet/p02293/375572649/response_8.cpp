#include <iostream>
#include <utility>
using namespace std;

int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    pair<double, double> k = { (bx - ax) * (dx - cx) - (by - ay) * (cy - dy), (bx - ax) * (cy - dy) + (by - ay) * (dx - cx) };
    if (k.second == 0)
      cout << "2\n";
    else if (k.first == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}