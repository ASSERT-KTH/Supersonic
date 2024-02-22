#include <cstdio> // for scanf and printf
#include <iostream> // for cin and cout
using namespace std;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by;
    cin >> cx >> cy >> dx >> dy;
    double x = (bx - ax) * (dx - cx);
    double y = (by - ay) * (cy - dy);
    double result = (y == 0) ? 2 : ((x == 0) ? 1 : 0);
    printf("%lf\n", result);
  }
  return 0;
}