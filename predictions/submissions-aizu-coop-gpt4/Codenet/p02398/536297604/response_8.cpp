#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  for (int i = 1; i <= sqrt(c); i++) {
    if (c % i == 0) {
      // Check if divisors are in range [a, b]
      if (a <= i && i <= b) {
        t++;
      }
      // Except when c is a perfect square
      int quotient = c / i;
      if (a <= quotient && quotient <= b && quotient != i) {
        t++;
      }
    }
  }
  cout << t << endl;
  return 0;
}