#include <bits/stdc++.h>
using namespace std;
typedef complex<double> P;
int main() {
  int n;
  double ax, ay, bx, by, cx, cy, dx, dy;
  ios_base::sync_with_stdio(false); // added for faster input/output
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n;
  while (n--) {
    cin >> ax >> ay >> bx >> by; // using cin instead of scanf
    cin >> cx >> cy >> dx >> dy;
    P k = P(bx - ax, by - ay) * P(dx - cx, cy - dy);
    if (k.imag() == 0)
      cout << "2\n"; // using cout instead of printf
    else if (k.real() == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  return 0;
}