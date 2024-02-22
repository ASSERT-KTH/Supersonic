#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;

  if (a > c || b < c) {
    cout << t << endl;
    return 0;
  }

  int sqrt_c = sqrt(c);
  for (s = c; s <= b && s <= sqrt_c; s++) {
    if (c % s == 0) {
      t += 2;
    }
  }
  
  if (s <= b && s * s == c) {
    t++;
  }

  cout << t << endl;
  return 0;
}