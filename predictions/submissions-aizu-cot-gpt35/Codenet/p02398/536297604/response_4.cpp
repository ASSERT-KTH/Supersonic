#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;
  
  int sqrt_c = sqrt(c);
  
  for (s = a; s <= sqrt_c; s++) {
    if (c % s == 0) {
      t++;
      if (s != c / s && s <= b) {
        t++;
      }
    }
  }
  
  cout << t << endl;
  return 0;
}