#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    P k = P(bx - ax, by - ay) * P(dx - cx, dy - cy);
    if (abs(k.imag()) < 1e-9)
      cout << "2\n";
    else if (abs(k.real()) < 1e-9)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}