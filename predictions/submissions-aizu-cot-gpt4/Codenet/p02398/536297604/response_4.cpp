#include <iostream>
using namespace std;
int main() {
  int a, b, c, s, t=0; // Initialize 't' to 0
  cin >> a >> b >> c;
  if (c < a) { // If 'c' is less than 'a', print '0' and return
    cout << 0 << endl;
    return 0;
  }
  // Otherwise, start the loop from 'a', or from 'c' if 'c' is within the range from 'a' to 'b'
  for (s = max(a, c); s <= b; s++) {
    if (c % s == 0) {
      t++;
    }
  }
  cout << t << endl;
  return 0;
}