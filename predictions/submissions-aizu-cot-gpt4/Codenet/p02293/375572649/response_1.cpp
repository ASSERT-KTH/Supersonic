#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  
  while (n--) {
    double ax, ay, bx, by, cx, cy, dx, dy;
    cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy;
    
    double real = (bx - ax) * (dx - cx) - (by - ay) * (cy - dy);
    double imag = (bx - ax) * (cy - dy) + (by - ay) * (dx - cx);
    
    if (imag == 0)
      cout << "2\n";
    else if (real == 0)
      cout << "1\n";
    else
      cout << "0\n";
  }
  
  return 0;
}