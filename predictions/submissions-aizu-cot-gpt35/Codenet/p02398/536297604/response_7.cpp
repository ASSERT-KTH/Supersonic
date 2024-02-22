#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b, c, t = 0;
  cin >> a >> b >> c;
  
  // Reduce the search space for divisors up to sqrt(c)
  int sqrt_c = sqrt(c);
  
  for (int s = a; s <= b; s++) {
    if (c % s == 0) {
      t++;
      
      // Check the other divisor c/s
      if (s != c/s) {
        t++;
      }
    }
  }
  
  cout << t << endl;
  return 0;
}