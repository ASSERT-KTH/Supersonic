#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int a, b, c, s, t = 0;
  cin >> a >> b >> c;
  
  for (s = max(1, a); s <= b; s++) {
    if (c % s == 0) {
      ++t;
    }
  }
  
  cout << t << '\n';
  return 0;
}