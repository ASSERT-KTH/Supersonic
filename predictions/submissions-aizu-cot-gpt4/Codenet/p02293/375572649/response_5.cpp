#include <iostream>
#include <complex>
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
    double realPart = (bx - ax) * (dx - cx);
    double imagPart = (by - ay) * (cy - dy);

    if (imagPart == 0)
      cout << "2\n";
    else if (realPart == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  
  return 0;
}