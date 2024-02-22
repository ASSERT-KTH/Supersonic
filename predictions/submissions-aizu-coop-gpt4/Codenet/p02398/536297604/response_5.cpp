#include <iostream>
using namespace std;
int main() {
  int a, b, c, s, t = 0;  // initialize 't' to zero
  cin >> a >> b >> c;
  int limit = min(b, c);  // compute the upper limit for the loop
  for (s = a; s <= limit; s++) {
    if (c != 0 && c < s)  // replace modulus with comparison where possible
      break;
    else if (c % s == 0)
      t++;
  }
  cout << t << endl;
  return 0;
}