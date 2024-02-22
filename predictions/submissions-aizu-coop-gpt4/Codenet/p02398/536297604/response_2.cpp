#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;
  a = max(1, a); // ensure a is not less than 1
  for (s = a; s <= min(b, (int)sqrt(c)); s++) {
    if (c % s == 0) {
      t++;
      if(s != c / s && c / s >= a && c / s <= b) t++; // check if the pair divisor falls within the range
    }
  }
  cout << t << endl;
  return 0;
}