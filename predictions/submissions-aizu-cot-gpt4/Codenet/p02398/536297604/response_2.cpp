#include <iostream>
using namespace std;
int main() {
  int a, b, c, s, t = 0; // Initialize 't' to 0
  cin >> a >> b >> c;
  for (s = min(c/b, b); s >= a; s--) { // Start from the maximum possible divisor
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}