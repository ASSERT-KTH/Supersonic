#include <iostream>
#include <algorithm> // for std::min
using namespace std;
int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;
  if (c == 0) {
    t = b - a + 1;
  } else {
    for (s = a; s <= min(b, c); s++) {
      if (c % s == 0) {
        t++;
      }
    }
  }
  cout << t << endl;
  return 0;
}