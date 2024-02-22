#include <iostream>
#include <cmath> // for sqrt function
using namespace std;

int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;

  // Go up to the sqrt of c
  for (int s = 1; s * s <= c; s++) {
    if (c % s == 0) {
      // 's' is a factor of 'c'
      if (s >= a && s <= b) {
        t++;
      }
      // 'c/s' is another factor of 'c'
      if (s != c/s && c/s >= a && c/s <= b) {
        t++;
      }
    }
  }

  cout << t << endl;
  return 0;
}