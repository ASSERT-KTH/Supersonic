#include <iostream>
#include <algorithm>
using namespace std;
int main() {
  int a, b, c, s, t = 0; // initialize 't' to 0
  cin >> a >> b >> c;
  if (c == 0) { // if 'c' is 0
    if (a <= 0) { // if 'a' is 0, output 'b - a + 1' directly and return
      cout << b - a + 1 << endl;
      return 0;
    } else { // if 'a' is not 0, output 'b - a' directly and return
      cout << b - a << endl;
      return 0;
    }
  }
  // if 'c' is not 0, start from the max value of 'a' and 'c / b', stop at the min value of 'b' and 'c'
  for (s = max(a, c / b); s <= min(b, c); s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}